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

#include <iostream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>

#include "daemon/daemon.h"
#include "config/cli_header.h"
#include "service/account_service.h"

// we should perhaps move this later
enum MenuOption {
    REGISTER,
    LOGIN,
    QUIT
};

MenuOption resolveOption(const std::string& input) {
    if (input == "/register") return REGISTER;
    if (input == "/login") return LOGIN;
    if (input == "/q") return QUIT;
}

int main(int argc, char* argv[])
{
    // will use the program arguments above for --help (--version etc)

    if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        std::stringstream ss;
        ss << std::endl 
        << "--version"
        << std::endl;

        std::cout << ss.str();

        // closing app
        return 0;
    }


    std::cout << hugin::getProjectCLIHeader();
        
    service::AccountService as;

    bool running = true;

    while (running) 
    {
        std::string option;

        std::cout << "> ";
        std::cin >> option;

        MenuOption menuOption = resolveOption(option);

        std::string username;
        std::string password;

        switch (menuOption)
        {
            case REGISTER:
            {
                std::cout << "Enter username: ";
                std::cin >> username;

                std::cout << "Enter password: ";
                std::cin >> password;
                as.createAccount(username, password);
                break;
            }
            case LOGIN:
            {
                std::cout << "Enter username: ";
                std::cin >> username;

                std::cout << "Enter password: ";
                std::cin >> password;
                as.loginAccount(username, password);
                break;
            }
            case QUIT:
            {
                std::cout << "Good Bye!" << std::endl;
                running = false;
                break;
            }
            default:
            {
                std::cout << "Wrong input!" << std::endl;
                break;
            }
        }
    }
    
    return 0;
}