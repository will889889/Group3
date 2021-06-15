/*
Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */
#include "RequestData.h"

namespace shortlink {

// Constructor
RequestData::RequestData() = default;

// Destructor
RequestData::~RequestData() = default;

// Constructor
RequestData::RequestData(const std::string tar,
                         const RequestType method)
    : target(tar), requestMethod(method) {}

}  // namespace shortlink
