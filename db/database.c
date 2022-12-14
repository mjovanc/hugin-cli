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

#include "database.h"
#include "config/hugin_config.h"
#include "sqlcipher/sqlite3.h"

int database_create(char *database_name, const char *database_password)
{
    sqlite3 *db;
    int rc;
    char *extension = ".db";
    char *full_db_name = strcat(database_name, extension);
	const char *pragma_sql = "PRAGMA key = 'passphrase'";


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

	// closing to save the database to file system
	sqlite3_close(db);

	char *setting_table_sql = "DROP TABLE IF EXISTS main.setting;"
				"CREATE TABLE main.setting(id INT PRIMARY KEY, name TEXT NOT NULL UNIQUE, domain TEXT, port INT, ssl INT, cache INT, version TEXT, fee REAL, proxy_url TEXT);";

	char *post_table_sql = "DROP TABLE IF EXISTS main.post;"
				"CREATE TABLE main.post(id INT PRIMARY KEY, message TEXT NOT NULL, nickname TEXT,"
				" time INT NOT NULL, board TEXT NOT NULL, key TEXT NOT NULL, signature TEXT NOT NULL, tx_hash TEXT NOT NULL);";

    // initializing tables
	database_transaction(&full_db_name, setting_table_sql);
	database_transaction(&full_db_name, post_table_sql);

	// populate data
	node_list_t node_list[3] = {
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

	// loop through the node_list struct array and make inserts

	// char *setting_table_insert_sql = "INSERT INTO main.setting VALUES(1, 'node', 'swepool.org:11898');";

	// database_transaction(db, zErrMsg, rc, setting_table_sql);

    return 0;
}

int database_transaction(const char **database_name, const char *sql)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open(*database_name, &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 1;
	}
	else
	{
		printf("Opened database successfully\n");
	}

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);

		return 1;
	}

	sqlite3_close(db);

	return 0;
}

int database_open(const char *database_name)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *extension = ".db";
    char *full_db_name = strcat(database_name, extension);

    //TODO: need to save this DB on user/local or similar OS systems not in the same place where executable is
    //TODO: and encrypt

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
    sqlite3_close(db);

    return 0;
}

int database_delete(const char *database_name)
{
    return 0;
}
