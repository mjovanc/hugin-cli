// Copyright (c) 2022-2023, The Kryptokrona Developers
//
// Created by Marcus Cvjeticanin
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or
//    other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <ncurses.h>

#include "core/window_main.h"

int main(int argc, char *argv[])
{
	/* NCURSES START */
	initscr();
	noecho();
	cbreak();

	// check if the terminal don't have support for colors
	if (!has_colors())
	{
		// we probably do not want to exit the program, but perhaps disable init colors
		return -1;
	}
	start_color();

	const short DARK_GREY = 233;
	const short LIGHT_GREY = 251;
	const short GREEN = 22;
	const short GREEN_DEEP_SEA = 74;

	// setting up colors
	init_pair(1, LIGHT_GREY, DARK_GREY); // LIGHT GREY + DARK GREY
	init_pair(2, GREEN, DARK_GREY); // GREEN + DARK GREY
	init_pair(3, LIGHT_GREY, GREEN); // LIGHT GREY + GREEN
	init_pair(4, GREEN_DEEP_SEA, DARK_GREY);
	wbkgd(stdscr, COLOR_PAIR(1));
	refresh();

	// init windows
	WINDOW *win_header = window_main_header_init();
	WINDOW *win_main_menu = window_main_menu_init();

	// start main based on user choice
	window_main_exec(win_header, win_main_menu);

	// end standard screen
	endwin();

	return 0;
}
