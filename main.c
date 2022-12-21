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

#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "core/window.h"
#include "core/window_login.h"
#include "account/account.h"
#include "common/error_code.h"
#include "config/cli_header.h"

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

	init_pair(1, 251, 233); // LIGHT GREY + DARK GREY
	init_pair(2, 22, 233); // GREEN + DARK GREY
	wbkgd(stdscr, COLOR_PAIR(1));
	refresh();

	// header window
	WINDOW *header_win = window_create(17, 95, 1, 2);
	print_header(header_win);
	wrefresh(header_win);

	// get screen size
	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);

	// main menu window
	WINDOW *menu_win = window_create(10, 95, 18, 2);
	wbkgd(menu_win, COLOR_PAIR(1));
	box(menu_win, 0, 0);

	wrefresh(menu_win);
	keypad(menu_win, true);

	const char *MENU_CHOICES[3] = {
		"Login",
		"Register",
		"Quit"
	};
	const char *MENU_CHOICES_DESC[3] = {
		"Login with your account.",
		"Register a new account.",
		"Quit the application."
	};
	int choice;
	int highlight = 0;

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(menu_win, A_REVERSE);

			mvwprintw(menu_win, i + 1, 1, "%-25s%-20s", MENU_CHOICES[i], MENU_CHOICES_DESC[i]);
			wattroff(menu_win, A_REVERSE);
		}
		choice = wgetch(menu_win);

		switch (choice)
		{
			case KEY_UP:
				highlight--;
				if (highlight == -1)
					highlight = 0;
				break;

			case KEY_DOWN:
				highlight++;
				if (highlight > 2)
					highlight = 2;
				break;

			default:
				break;
		}

		// 10 is the enter key
		if (choice == 10)
			break;
	}

	// new switch here with highlight option and do different things with it

	switch (highlight)
	{
	case 0:
		window_delete(header_win);
		window_delete(menu_win);
		window_login_init();
		break;
	case 1:
		window_delete(header_win);
		window_delete(menu_win);
		break;
	case 2:
		window_delete(header_win);
		window_delete(menu_win);
		endwin();
		return 0;
	default:
		break;
	}

	// create new window

	// initialize window

	// printw("Your choice was: %s", MENU_CHOICES[highlight]);

	// refresh();

	getch();

	/*char input[10];
	  bool logged_in = false;

	  do
	  {
		  printf("> ");
		  scanf(" %9s", input);

		  if (strcmp(input, "/l") == 0)
		  {
			  if (logged_in == true)
			  {
							printw("%s\n", A00005);
				  continue;
			  }

			  if (account_login_prompt() != 0)
			  {
								  printw("%s\n", A00003);
				  continue;
			  }

			  logged_in = true;
		  }
		  else if (strcmp(input, "/r") == 0)
		  {
			  if (account_register_prompt() != 0)
			  {
								  printw("%s\n", A00004);
				  continue;
			  }

			  logged_in = true;
		  }
		  else if (strcmp(input, "/q") == 0)
		  {
			  account_logout(&logged_in); // only logout if we are logged in
						  printw("Good bye!\n");
		  }
		  else
		  {
			  printf("%s\n", C00006);
		  }
	  } while (strcmp(input, "/q") != 0);
	  {
		  getch();
	  }*/

	endwin();

	return 0;
}
