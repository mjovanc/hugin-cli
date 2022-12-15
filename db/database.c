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
#include <string.h>
#include <stdlib.h>

#include "sqlcipher/sqlite3.h"
#include "database.h"
#include "node.h"


int db_create(char *db_name, const char *db_password)
{
    sqlite3 *db;
    int rc;
    const char *extension = ".db";
    const char *full_db_name = strcat(db_name, extension);
	char *pragma_str1 = "PRAGMA key = '";
	char *pragma_str2 = "';";
	size_t pragma_size = strlen(pragma_str1) + strlen(pragma_str2);
	char *pragma_sql = malloc(sizeof(db_password) * pragma_size + 1);

	strncpy(pragma_sql, pragma_str1, pragma_size);
	strcat(pragma_sql, db_password);
	strcat(pragma_sql, pragma_str2);

	printf("PRAGMA KEY IS %s\n", pragma_sql);

    rc = sqlite3_open(full_db_name, &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    else
    {
        printf("Opened database successfully\n");
    }

	// not possible yet since the libsqlcipher does not have SQLITE_HAS_CODEC and SQLITE_TEMP_STORE in the CFLAGS
	// need probably to build it myself...
	// sqlite3_key(sqlite3 *db, const void *pKey, int nKey);

	// closing to save the database to file system
	sqlite3_close(db);

	char *node_table_sql = "DROP TABLE IF EXISTS main.node;"
						   "CREATE TABLE main.node(id INTEGER PRIMARY KEY, name TEXT NOT NULL UNIQUE, domain TEXT, port INTEGER, ssl INTEGER, cache INTEGER, version TEXT, fee REAL, proxy_url TEXT);";

	char *post_table_sql = "DROP TABLE IF EXISTS main.post;"
						   "CREATE TABLE main.post(id INTEGER PRIMARY KEY, message TEXT NOT NULL, nickname TEXT,"
						   " time INTEGER NOT NULL, board TEXT NOT NULL, key TEXT NOT NULL, signature TEXT NOT NULL, tx_hash TEXT NOT NULL);";

	char *setting_table_sql = "DROP TABLE IF EXISTS main.setting;"
							  "CREATE TABLE main.setting(id INTEGER PRIMARY KEY, node_id INTEGER, FOREIGN KEY(node_id) REFERENCES node(id));";

	char *wallet_table_sql = "DROP TABLE IF EXISTS main.wallet;"
							 "CREATE TABLE main.wallet(id INTEGER PRIMARY KEY, balance REAL, balance_locked REAL, mnemonic_seed TEXT NOT NULL, spend_key TEXT NOT NULL, view_key TEXT NOT NULL);";

	char *transaction_table_sql = "DROP TABLE IF EXISTS main.transaction;"
								  "CREATE TABLE main.transaction(id INTEGER PRIMARY KEY, hash TEXT, amount REAL, fee REAL);";


    // initializing tables
	db_transaction(&full_db_name, node_table_sql, db_password);
	db_transaction(&full_db_name, post_table_sql, db_password);
	db_transaction(&full_db_name, setting_table_sql, db_password);
	db_transaction(&full_db_name, wallet_table_sql, db_password);
	db_transaction(&full_db_name, transaction_table_sql, db_password);

	// populate data
	db_add_node_initial_data(&full_db_name, db_password);

	free(pragma_sql);

    return 0;
}



int db_delete(char *db_name)
{
    return 0;
}
