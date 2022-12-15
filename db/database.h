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

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <stdbool.h>
#include <stdint.h>

#include "core/core.h"
#include "sqlcipher/sqlite3.h"

//TODO: should we perhaps split the table operations to a different .c/.h file?
//  example would be database_post.h / database_post_encrypted.h or post.h / post_encrypted.h etc

int database_create(char *database_name, const char *database_password);
int database_transaction(const char **database_name, const char *sql, const char *database_password);

// node table
int database_add_node(const char *database_name, node_t node, const char *database_password);
int database_edit_node(const char *database_name, int node_id, const char *database_password);
int database_delete_node(const char *database_name, int node_id, const char *database_password);

// post table
int database_add_post(const char *database_name, post_t post, const char *database_password);
int database_delete_post(char *database_name, int post_id, const char *database_password);
int database_delete_post_all(char *database_name, const char *database_password);

// post_encrypted table
int database_add_post_encrypted();
int database_delete_post_encrypted();
int database_delete_post_encrypted_all();

// post_encrypted_group table
int database_add_post_encrypted_group();
int database_delete_post_encrypted_group();
int database_delete_post_encrypted_group_all();

int database_edit_password(char *database_name, const char *database_new_password);
int database_edit_setting(char *database_name, const char *database_password);

int database_delete(char *database_name);

#endif //DATABASE_DATABASE_H