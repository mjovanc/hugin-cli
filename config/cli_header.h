// Copyright (c) 2022-2022, The Kryptokrona Project
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

#include <sstream>
#include <config/hugin_config.h>
#include <config/ascii.h>
#include "version.h"

namespace hugin
{
  inline std::string getProjectCLIHeader()
  {
    std::stringstream ss;
    ss << std::endl
      << asciiArt << std::endl
      << "  " << parameters::HUGIN_NAME << " v" << PROJECT_VERSION << std::endl
      << "  This software is distributed under the General Public License v3.0"
      << std::endl << std::endl
      << "  " << PROJECT_COPYRIGHT << std::endl
      << "  Created by: Marcus Cvjeticanin"
      << std::endl << std::endl
      << "  Additional Copyright(s) may apply, please see the included LICENSE file for more information." << std::endl
      << "  If you did not receive a copy of the LICENSE, please visit:" << std::endl
      << "  " << parameters::LICENSE_URL
      << std::endl << std::endl;

    return ss.str();
  }
}