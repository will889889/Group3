/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */
#include "Parser.h"

#include "RequestData.h"

namespace shortlink {

// Constructor
Parser::Parser() = default;

// Destructor
Parser::~Parser() = default;

// Decodes the input string, returns the RequestData.
std::unique_ptr<RequestData> Parser::Parse(const std::string &rawData) {
  std::stringstream ss = std::stringstream(rawData);
  std::string method_str = "";
  std::string target_str = "";

  if (ss.peek() != EOF) ss >> method_str;
  if (ss.peek() != EOF) ss >> target_str;

  RequestType type = RequestType::kSearch;
  if (method_str == "Create") {
    type = RequestType::kCreate;
  } else if (method_str == "Search") {
    type = RequestType::kSearch;
  } else {
    // error: method not valid.
    type = RequestType::kInvalid;
    target_str = "";
  }

  return std::make_unique<RequestData>(target_str, type);
}

}  // namespace shortlink
