/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */
#include <gtest/gtest.h>

#include "Parser.h"
#include "RequestData.h"

TEST(ParserTest, ParseSearch) {
  std::string rawData = "Search ABCDEFG";
  std::unique_ptr<shortlink::RequestData> data =
      shortlink::Parser::Parse(rawData);

  std::string target_content = "ABCDEFG";
  EXPECT_EQ(data->requestMethod, shortlink::RequestType::kSearch);
  EXPECT_EQ(data->target, target_content);
}

TEST(ParserTest, ParseCreate) {
  std::string rawData = "Create https://www.google.com/";
  std::unique_ptr<shortlink::RequestData> data =
      shortlink::Parser::Parse(rawData);

  std::string target_content = "https://www.google.com/";
  EXPECT_EQ(data->requestMethod, shortlink::RequestType::kCreate);
  EXPECT_EQ(data->target, target_content);
}

TEST(ParserTest, ParseInvalidRequest) {
  std::string rawData = "hello World!";
  std::unique_ptr<shortlink::RequestData> data =
      shortlink::Parser::Parse(rawData);

  std::string target_content = "";
  EXPECT_EQ(data->requestMethod, shortlink::RequestType::kInvalid);
  EXPECT_EQ(data->target, target_content);
}

TEST(ParserTest, ParseInvalidFormat) {
  std::string rawData = "hello";
  std::unique_ptr<shortlink::RequestData> data =
      shortlink::Parser::Parse(rawData);

  std::string target_content = "";
  EXPECT_EQ(data->requestMethod, shortlink::RequestType::kInvalid);
  EXPECT_EQ(data->target, target_content);
}

TEST(ParserTest, ParseEmpty) {
  std::string rawData = "";
  std::unique_ptr<shortlink::RequestData> data =
      shortlink::Parser::Parse(rawData);

  std::string target_content = "";
  EXPECT_EQ(data->requestMethod, shortlink::RequestType::kInvalid);
  EXPECT_EQ(data->target, target_content);
}
