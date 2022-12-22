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

	WINDOW *win_chat_sb 		= window_create(max_y, max_x/6, 0, 0);
	WINDOW *win_chat_headline 	= window_create(1, max_x - (max_x/6), 0, max_x/6);
	WINDOW *win_chat_area 		= window_create(max_y-2, max_x - (max_x/6), 1, max_x/6);
	WINDOW *win_chat_status 	= window_create(1, max_x - (max_x/6), max_y-2, max_x/6);
	WINDOW *win_chat_text 		= window_create(1, max_x - (max_x/6), max_y-1, max_x/6);
	refresh();

	// set window colors
	wbkgd(win_chat_sb,   		COLOR_PAIR(4));
	wbkgd(win_chat_headline, 	COLOR_PAIR(3));
	wbkgd(win_chat_area, 		COLOR_PAIR(1));
	wbkgd(win_chat_status, 		COLOR_PAIR(3));
	wbkgd(win_chat_text, 		COLOR_PAIR(1));

	// setting borders
	int left, right, top, bottom, tlc, trc, blc, brc;
	bottom = top = left = right = (int) ' ';
	// tlc = trc = blc = brc = (int) ' ';
	int empty = (int) ' ';

	// set window borders
	// TODO: remove top left corner, top right corner, bottom left corner, bottom right corner (later)
	wborder(win_chat_sb, 		left, 0, 		top, bottom, empty, ACS_VLINE, empty, ACS_VLINE);
	wborder(win_chat_headline, 	left, right, 	top, bottom, empty, empty, empty, empty);
	wborder(win_chat_area, 		left, right, 	top, bottom, empty, empty, empty, empty);
	wborder(win_chat_status, 	left, right, 	top, bottom, empty, empty, empty, empty);
	wborder(win_chat_text, 		left, right, 	top, bottom, empty, empty, empty, empty);

	// refresh windows
	wrefresh(win_chat_sb);
	wrefresh(win_chat_headline);
	wrefresh(win_chat_area);
	wrefresh(win_chat_status);
	wrefresh(win_chat_text);

	getch();
}

