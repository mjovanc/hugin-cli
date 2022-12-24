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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "core/log.h"
#include "db/database.h"
#include "wallet.h"

bool wallet_exists(const std::string wallet_name)
{
	//TODO: improve this concatenation with https://stackoverflow.com/questions/74811161/how-to-create-efficient-function-in-c-for-handling-multiple-arguments-to-be-form
	char *extension = ".db";
	size_t tmp_wallet_size = strlen(wallet_name) + strlen(extension);
	char *tmp_wallet_name;
	tmp_wallet_name = malloc(sizeof(*tmp_wallet_name) * tmp_wallet_size + 1);

	strncpy(tmp_wallet_name, wallet_name, tmp_wallet_size);
	strcat(tmp_wallet_name, extension);

	// wallet already exists
	if (access(tmp_wallet_name, F_OK) == 0) {
		//TODO: print to file instead
		// log_info("Wallet already exists...");
		free(tmp_wallet_name);
		return true;
	}

	free(tmp_wallet_name);

	return false;
}

bool wallet_create(const std::string wallet_name, const std::string wallet_password)
{
	if (wallet_exists(wallet_name)) {
		return false;
	}

	//TODO: print to file instead
	// log_info("Creating wallet and database...");
	db_create(wallet_name, wallet_password);

	return true;
}

bool wallet_open(const std::string wallet_name, const std::string wallet_password)
{
	return true;
}