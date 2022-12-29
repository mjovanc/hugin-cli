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

#include <string>

#include "database.h"
#include "log.h"
#include "node.h"
#include "sqlite3.h"
#include "transaction.h"

int db_create(std::string db_name, const std::string db_password)
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int rc;
	//TODO: change this concatenation to sprintf later as on node.c
	std::string extension = ".db";
	std::string full_db_name = db_name + extension;

	rc = sqlite3_open(full_db_name.c_str(), &db);
	if (rc != SQLITE_OK) {
		//TODO: print to file instead
		// log_error("Can't open database: %s", sqlite3_errmsg(db));
		return 1;
	}

	//TODO: does not work currently
	// setting the pragma key
	char pragma_sql[1024];
	snprintf(pragma_sql, sizeof(pragma_sql), "PRAGMA KEY='%s';", db_password);

	sqlite3_prepare_v2(db, pragma_sql, -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		//TODO: print to file instead
		// log_error("Can't run SQL statement: %s", sqlite3_errmsg(db));
		return 1;
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);// closing to save the database to file system

	// not possible yet since the libsqlcipher does not have SQLITE_HAS_CODEC and SQLITE_TEMP_STORE in the CFLAGS
	// need probably to build it myself...
	// sqlite3_key(sqlite3 *db, const void *pKey, int nKey);

	const std::string node_table_sql = "DROP TABLE IF EXISTS main.node;"
									   "CREATE TABLE main.node(id INTEGER PRIMARY KEY, name TEXT NOT NULL UNIQUE, domain TEXT, port INTEGER,"
									   " ssl INTEGER, cache INTEGER, version TEXT, fee REAL, proxy_url TEXT);";

	const std::string post_table_sql = "DROP TABLE IF EXISTS main.post;"
									   "CREATE TABLE main.post(id INTEGER PRIMARY KEY, message TEXT NOT NULL, nickname TEXT,"
									   " time INTEGER NOT NULL, board TEXT NOT NULL, key TEXT NOT NULL, signature TEXT NOT NULL, tx_hash TEXT NOT NULL);";

	const std::string setting_table_sql = "DROP TABLE IF EXISTS main.setting;"
										  "CREATE TABLE main.setting(id INTEGER PRIMARY KEY, node_id INTEGER, FOREIGN KEY(node_id) REFERENCES node(id));";

	const std::string wallet_table_sql = "DROP TABLE IF EXISTS main.wallet;"
										 "CREATE TABLE main.wallet(id INTEGER PRIMARY KEY, balance REAL, balance_locked REAL, mnemonic_seed TEXT NOT NULL,"
										 " spend_key TEXT NOT NULL, view_key TEXT NOT NULL);";

	const std::string transaction_table_sql = "DROP TABLE IF EXISTS main.txn;"
											  "CREATE TABLE main.txn(id INTEGER PRIMARY KEY, hash TEXT, amount REAL, fee REAL);";

	// creating tables
	db_transaction(full_db_name, node_table_sql, db_password);
	db_transaction(full_db_name, post_table_sql, db_password);
	db_transaction(full_db_name, setting_table_sql, db_password);
	db_transaction(full_db_name, wallet_table_sql, db_password);
	db_transaction(full_db_name, transaction_table_sql, db_password);

	// populate node table data
	db_add_node_initial_data(full_db_name, db_password);

	return 0;
}

int db_delete(char *db_name)
{
	return 0;
}
