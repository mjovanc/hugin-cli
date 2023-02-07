// Copyright (c) 2022-2023, The Kryptokrona Developers
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

#include "sqlcipher/sqlite3.h"

#include "core/log.h"

int db_transaction(const char **db_name, const char *sql, const char *db_password)
{
	sqlite3 *db;
	sqlite3_stmt* stmt;
	char *zErrMsg = 0;
	int rc;

	//TODO: should open the database with password
	rc = sqlite3_open(*db_name, &db);
	if (rc != SQLITE_OK)
	{
		log_error("Can't open database: %s", sqlite3_errmsg(db));
		return 1;
	}

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		log_error("SQL error: %s", sqlite3_errmsg(db));
		sqlite3_free(zErrMsg);
		sqlite3_close(db);

		return 1;
	}

	sqlite3_close(db);

	return 0;
}

int db_transaction_prepared(const char **db_name, const char *sql, const char *db_password)
{
	sqlite3 *db;
	sqlite3_stmt* stmt;
	char *zErrMsg = 0;
	int rc;

	//TODO: should open the database with password
	rc = sqlite3_open(*db_name, &db);
	if (rc != SQLITE_OK)
	{
		log_error("Can't open database: %s", sqlite3_errmsg(db));
		return 1;
	}

	int prepared_stmt = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
	if (prepared_stmt != 0)
	{
		log_error("Can't execute prepared database transaction: %s", sqlite3_errmsg(db));
		return 1;
	}

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		log_error("Can't run SQL statement: %s", sqlite3_errmsg(db));
		return 1;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return 0;
}

