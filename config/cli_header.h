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

#ifndef CONFIG_CLI_HEADER_H
#define CONFIG_CLI_HEADER_H

#include <stdio.h>

#include "ncurses.h"
#include "version.h"

void print_header(WINDOW *header_win)
{
	wattron(header_win, COLOR_PAIR(2));
	mvwprintw(header_win, 0, 0,
			  "     __  __            _          ________    ____\n"
			  "    / / / __  ______ _(_____     / ____/ /   /  _/\n"
			  "   / /_/ / / / / __ `/ / __ \\   / /   / /    / /\n"
			  "  / __  / /_/ / /_/ / / / / /  / /___/ /____/ /\n"
			  " /_/ /_/\\__,_/\\__, /_/_/ /_/   \\____/_____/___/\n"
			  "             /____/\n\n");

	wattron(header_win, COLOR_PAIR(1));
	mvwprintw(header_win, 7, 0, " %s v%s\n", PROJECT_NAME, PROJECT_VERSION);
	mvwprintw(header_win, 8, 0, " This software is licensed under BSD-3 License.\n\n");
	mvwprintw(header_win, 10, 0, " %s\n", PROJECT_COPYRIGHT);
	mvwprintw(header_win, 11, 0, " Created by %s\n\n", PROJECT_AUTHOR);
	mvwprintw(header_win, 13, 0, " Additional Copyright(s) may apply, please see the included LICENSE file for more information.\n");
	mvwprintw(header_win, 14, 0, " If you did not receive a copy of the LICENSE, please visit:\n");
	mvwprintw(header_win, 15, 0, " %s\n\n", PROJECT_LICENSE_URL);
}

#endif//CONFIG_CLI_HEADER_H