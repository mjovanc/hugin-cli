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

#include <stdio.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#endif

#include "wallet.h"
#include "db/database.h"

int wallet_create(char *wallet_name, char *wallet_password)
{
    char *extension = ".db";
    size_t tmp_wallet_size = strlen(wallet_name) + strlen(extension);
    char *tmp_wallet_name;
    tmp_wallet_name = malloc(sizeof(*tmp_wallet_name) * tmp_wallet_size + 1);

    strncpy(tmp_wallet_name, wallet_name, tmp_wallet_size);
    strcat(tmp_wallet_name, extension);

    // wallet already exists
    if (access(tmp_wallet_name, F_OK) == 0)
    {
        return 1;
    }

    free(tmp_wallet_name);

    printf("Creating wallet...\n");
    database_create(wallet_name);

    return 0;
}

bool wallet_exists(char *wallet_name)
{
    char *extension = ".db";
    size_t tmp_wallet_size = strlen(wallet_name) + strlen(extension);
    char *tmp_wallet_name;
    tmp_wallet_name = malloc(sizeof(*tmp_wallet_name) * tmp_wallet_size + 1);

    strncpy(tmp_wallet_name, wallet_name, tmp_wallet_size);
    strcat(tmp_wallet_name, extension);

    // wallet already exists
    if (access(tmp_wallet_name, F_OK) == 0)
    {
        return 1;
    }

    free(tmp_wallet_name);
    return 0;
}

int wallet_open(char *wallet_name, char *wallet_password)
{
    return 0;
}