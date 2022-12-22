// Copyright (c) 2022-2022, The Kryptokrona Developers
//
// Created by Marcus Cvjeticanin
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list
//    of conditions and the following disclaimer in the documentation and/or
//    other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be
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

#include "window.h"

void window_chat_init()
{
	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);

	WINDOW *win_chat_sb = window_create(max_y-5, max_x/4, 0, 0);
	WINDOW *win_chat_area = window_create(max_y-5, max_x/2, 0, max_x/2);
	WINDOW *win_chat_text = window_create(5, max_x, max_y-5, 0);
	refresh();

	// set background
	wbkgd(win_chat_sb, COLOR_PAIR(1));
	wbkgd(win_chat_area, COLOR_PAIR(1));
	wbkgd(win_chat_text, COLOR_PAIR(1));

	// create box
	box(win_chat_sb, 0, 0);
	box(win_chat_area, 0, 0);
	box(win_chat_text, 0, 0);

	// refresh windows
	wrefresh(win_chat_sb);
	wrefresh(win_chat_area);
	wrefresh(win_chat_text);

	getch();
}

