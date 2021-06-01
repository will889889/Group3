#Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
#All rights reserved.
#Use of this source code is governed by a BSD-style license that can be
#found in the LICENSE file. See the AUTHORS file for names of contributors.
cmake_minimum_required(VERSION 3.14)

project(ShortLink)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories (${SRC_DIR})

add_executable(ShortLink ${SRC_DIR}/main.cpp)