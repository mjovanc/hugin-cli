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

const std::string windowsAsciiArt =
      "\n _                    _        _      \n"
        "| |__ _ _  _ _  ___ _| |_ ___ | |__ _ _  ___ ._ _  ___  \n"
        "| / /| '_>| | || . \\ | | / . \\| / /| '_>/ . \\| ' |<_> | \n"
        "|_\\_\\|_|  `_. ||  _/ |_| \\___/|_\\_\\|_|  \\___/|_|_|<___| \n"
        "          <___'|_|                                      \n";

const std::string nonWindowsAsciiArt =
      "     .---.        .-----------
     /     \\  __  /    ------
    / /     \\(  )/    -----
   //////   ' \\/ `   ---
  //// / // :    : ---
 // /   /  /`    '--
//          //..\\
       ====UU====UU====
           '//||\\`
             ''``
          Hugin CLI";

/* windows has some characters it won't display in a terminal. If your ascii
   art works fine on windows and linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32
const std::string asciiArt = windowsAsciiArt;
#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif