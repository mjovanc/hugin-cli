# Copyright (c) 2022-2022, The Kryptokrona Project
#
# Created by Marcus Cvjeticanin
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are
# permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this list of
# conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice, this list
# of conditions and the following disclaimer in the documentation and/or other
# materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be
# used to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
# THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
# THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

cmake_minimum_required(VERSION 3.18)

# set the project name
project(Hugin)

# specify the C standard (17 or higher does not work yet)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")
message(STATUS "Building with ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} on ${CMAKE_SYSTEM}")

include(FetchContent)

# update the commit to point to whatever libsodium-cmake-commit you want to target.
# if this repo stops being maintained - make a fork and change url
FetchContent_Declare(Sodium
        GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
        GIT_TAG 99f14233eab1d4f7f49c2af4ec836f2e701c445e # HEAD as of 2022-05-28
        )
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

# directories to be included
include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.c)

# install the executable in /usr/local/bin
# uncomment this later
# make install (instead of only make)
# now we can run it with only Hugin instead of writing the whole path
#install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# add the subdirectories to look for cmake files
add_subdirectory(crypto)
add_subdirectory(daemon)
add_subdirectory(db)
add_subdirectory(account)
add_subdirectory(wallet)
add_subdirectory(external)
add_subdirectory(external/cunit/CUnit)

# sqlcipher
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(FindPkgConfig)
find_package(Sqlcipher REQUIRED)
include_directories(${SQLCIPHER_INCLUDE_DIR})

# include directories (order is important)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        crypto
        daemon
        account
        wallet
        db
        common
        config
)

# link libraries (order is important)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${SQLCIPHER_LIBRARY}
        crypto
        daemon
        account
        wallet
        db
    PRIVATE
        sodium
)
