#Copyright (c) 2021 Chiu Yen-Chen, Swen Sun-Yen, Wen Yong-Wei, Yuan Wei-Chen.
#All rights reserved.
#Use of this source code is governed by a BSD-style license that can be
#found in the LICENSE file. See the AUTHORS file for names of contributors.
cmake_minimum_required(VERSION 3.14)

project(ShortLink)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

if (WIN32)
  # For google test
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif ()

include_directories (${SRC_DIR})

add_executable(ShortLink 
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/RequestData.h
  ${SRC_DIR}/RequestData.cpp
  ${SRC_DIR}/Parser.h
  ${SRC_DIR}/Parser.cpp
)

# For testing files
enable_testing()

add_executable(parser_test
  ${SRC_DIR}/RequestData.h
  ${SRC_DIR}/RequestData.cpp
  ${SRC_DIR}/Parser.h
  ${SRC_DIR}/Parser.cpp
  ${SRC_DIR}/UnitTestParser.cpp
)
target_link_libraries(
  parser_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(parser_test)
