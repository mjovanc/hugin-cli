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

#include <stdlib.h>
#include <string.h>

#include "sqlcipher/sqlite3.h"
#include "core/core.h"

int db_add_node_initial_data(const char *db_name, const char *db_password)
{
	node_t node_list[3] = {
		{
			"Swepool",
			"swepool.org",
			11898,
			false,
			false,
			"0.0.1",
			0.00,
			"swepool"
		},
		{
			"Göta Pool",
			"gota.kryptokrona.se",
			11898,
			false,
			false,
			"0.0.1",
			0.00,
			"gota"
		},
		{
			"Blocksum",
			"blocksum.or",
			11898,
			false,
			false,
			"0.1.0",
			0.00,
			"blocksum"
		},
	};

	for (int n = 0; n < 3; n++)
	{
	  // populate db

	  char *pragma_str1 = "INSERT INTO main.node VALUES(";
	  char *pragma_str2 = "';";
	  size_t pragma_size = strlen(pragma_str1) + strlen(pragma_str2);
	  char *pragma_sql = malloc(sizeof(db_password) * pragma_size + 1);

	  strncpy(pragma_sql, pragma_str1, pragma_size);
	  strcat(pragma_sql, db_password);
	  strcat(pragma_sql, pragma_str2);

	  // db_add_node();
	}

	// char *setting_table_insert_sql = "INSERT INTO main.setting VALUES(1, 'node', 'swepool.org:11898');";

	return 0;
}

int db_add_node(const char *db_name, node_t node, const char *db_password)
{
	return 0;
}