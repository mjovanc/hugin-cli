// Copyright (c) 2022-2022, The Kryptokrona Developers
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

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h> // TODO: need to implement this later

#include "account/account.h"
#include "config/cli_header.h"
#include "common/error_code.h"

int main(int argc, char *argv[])
{
    int logo = puts(
        "      __  __            _          ________    ____\n"
        "     / / / __  ______ _(_____     / ____/ /   /  _/\n"
        "    / /_/ / / / / __ `/ / __ \\   / /   / /    / /\n"
        "   / __  / /_/ / /_/ / / / / /  / /___/ /____/ /\n"
        "  /_/ /_/\\__,_/\\__, /_/_/ /_/   \\____/_____/___/\n"
        "              /____/\n");

    if (logo == EOF)
        perror("puts()"); // required by POSIX that errno is set

    print_header();

    char input[10];
    bool logged_in = false;

    do
    {
        printf("> ");
        scanf(" %9s", input);

        if (strcmp(input, "/l") == 0)
        {
            if (logged_in == true)
            {
                printf("%s\n", A00005);
                continue;
            }

            if (account_login_prompt() != 0)
            {
                printf("%s\n", A00003);
                continue;
            }

            logged_in = true;
        }
        else if (strcmp(input, "/r") == 0)
        {
            if (account_register_prompt() != 0)
            {
                printf("%s\n", A00004);
                continue;
            }

            logged_in = true;
        }
        else if (strcmp(input, "/q") == 0)
        {
            account_logout(&logged_in); // only logout if we are logged in
            printf("Good bye!\n");
        }
        else
        {
            printf("%s\n", C00006);
        }
    } while (strcmp(input, "/q") != 0);
    {
        getchar();
    }

    return 0;
}
