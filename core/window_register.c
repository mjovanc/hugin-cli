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

#include <form.h>

#include "window.h"

void window_register_init()
{
	WINDOW *win_login = window_create(0, 0, 0, 0);
	wbkgd(win_login, COLOR_PAIR(1));
	box(win_login, 0, 0);
	wrefresh(win_login);

	FIELD *field[4];
	FORM  *my_form;
	int ch;

	/* Initialize curses */
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 40, 4, 35, 0, 0);
	field[1] = new_field(1, 40, 6, 35, 0, 0);
	field[2] = new_field(1, 40, 8, 35, 0, 0);
	field[3] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
	/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE);
	// field_opts_off(field[1], O_PUBLIC); // makes the field input hidden
	field_opts_off(field[1], O_AUTOSKIP);

	set_field_back(field[2], A_UNDERLINE);
	// field_opts_off(field[2], O_PUBLIC); // makes the field input hidden
	field_opts_off(field[2], O_AUTOSKIP);

	//TODO: https://www.mkssoftware.com/docs/man3/form_field_validation.3.asp ?

	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();

	mvprintw(4, 10, "Username:");
	mvprintw(6, 10, "Password:");
	mvprintw(8, 10, "Password (again):");
	refresh();

	move(4, 35);

	/* Loop through to get user requests */
	while ((ch = getch()) != 10)
	{
		switch(ch)
		{
		case KEY_DOWN:
			/* Go to next field */
			form_driver(my_form, REQ_NEXT_FIELD);
			/* Go to the end of the present buffer */
			/* Leaves nicely at the last character */
			form_driver(my_form, REQ_END_LINE);
			break;
		case KEY_UP:
			/* Go to previous field */
			form_driver(my_form, REQ_PREV_FIELD);
			form_driver(my_form, REQ_END_LINE);
			break;
		default:
			/* If this is a normal character, it gets */
			/* Printed				  */
			form_driver(my_form, ch);
			break;
		}
	}

	mvprintw(1,10, "%s\n", field_buffer(field[0], 0));

	getch();

	/*if (form_driver(my_form, REQ_VALIDATION) != E_OK) {
		// do something
	}*/



	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);
	free_field(field[2]);
}