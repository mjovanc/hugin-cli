// Copyright (c) 2022-2023, The Kryptokrona Developers
//
// Created by Marcus Cvjeticanin
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define PROJECT_NAME "Hugin CLI"
#define PROJECT_SITE "https://www.kryptokrona.org"
#define PROJECT_COPYRIGHT "Copyright 2022, Kryptokrona"
#define PROJECT_AUTHOR "Marcus Cvjeticanin"
#define PROJECT_LICENSE_URL "https://github.com/kryptokrona/hugin-cli/blob/master/LICENSE"
#define APP_VER_MAJOR 0
#define APP_VER_MINOR 1
#define APP_VER_REV 0

#define PROJECT_VERSION STR(APP_VER_MAJOR) "." STR(APP_VER_MINOR) "." STR(APP_VER_REV)
#define PROJECT_DESCRIPTION PROJECT_NAME " " PROJECT_VERSION