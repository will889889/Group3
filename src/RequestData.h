/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
*/
#ifndef SHORTLINK_SRC_REQUESTDATA_H_
#define SHORTLINK_SRC_REQUESTDATA_H_
#include <string>

namespace shortlink {

// For every RequestData, it might has a type of Create, Search, and Invalid.
enum RequestType { kInvalid, kSearch, kCreate };

// RequestData is a class of a data structure that represents a request that a
// user sends to the server. Example:
//    RequestData data = RequestData();
//    data.target = "3arUqBH";
//    data.requestMethod = "Search";
class RequestData {
 public:
  // Default constructor, all memeber variables would be 0 or "";
  RequestData();
  // Constructor that sets all the memeber variables with the parameters.
  RequestData(const std::string _target, const RequestType _requestMethod);
  // Default destructor
  ~RequestData();

  std::string target;
  RequestType requestMethod;
};

}  // namespace shortlink

#endif  // SHORTLINKSERVER_SRC_REQUESTDATA_H_
