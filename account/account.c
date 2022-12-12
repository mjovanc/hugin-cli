// Copyright (c) 2022-2022, The Kryptokrona Project
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

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "account.h"
#include "common/error_code.h"
#include "wallet/wallet.h"

int account_login_prompt() {
  char username_input[20];
  char password_input[50];

  do {
	printf("Enter username: ");
	scanf(" %19s", username_input);

	// check for blank
	if (strlen(username_input) > 49) {
	  printf("%s\n", A00001);
	  return 1;
	}

	printf("Enter password: ");
	scanf(" %49s", password_input);

	if (strlen(password_input) > 19) {
	  printf("%s\n", A00002);
	  return 1;
	}

	// check for blank input
  } while (
	  (strlen(username_input) > 49) && (strlen(password_input) > 19));
  {
	getchar();
  }

  return account_login(username_input, password_input);
}

int account_register_prompt() {
  char username_input[20];
  char password_input[50];

  do {
	printf("Enter username: ");
	scanf(" %19s", username_input);

	printf("Enter password: ");
	scanf(" %49s", password_input);

	// check for blank input
	if (strlen(username_input) > 49) {
	  printf("%s\n", A00001);
	  return 1;
	}

	// check for blank input
	if (strlen(password_input) > 19) {
	  printf("%s\n", A00002);
	  return 1;
	}

	// check for blank input
  } while (
	  (strlen(username_input) > 49) && (strlen(password_input) > 19));
  {
	getchar();
  }

  return account_register(username_input, password_input);
}

int account_login(char *username, char *password) {
  // TODO: this does not work since the file is created after exeuction of program exists
  bool exists = wallet_exists(username);

  if (!exists) {
	printf("%s\n", W00002);
	return 1;
  }

  printf("Logged in...\n");

  return 0;
}

int account_register(char *username, char *password) {
  bool wallet_created = wallet_create(username, password);
  if (!wallet_created) {
	printf("%s\n", W00001);
	return 1;
  }

  return account_login(username, password);
}

int account_logout(bool *logged_in) {
  // check if we are logged in first before logging out

  printf("Logging out...\n");

  return 0;
}
