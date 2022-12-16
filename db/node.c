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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sqlcipher/sqlite3.h"
#include "core/core.h"
#include "core/log.h"
#include "transaction.h"

int db_add_node(const char **db_name, node_t node, const char *db_password)
{
  	// prepare prepared transaction char array to pass to db_transaction_prepared below
	char sql[1024];
	int ssl = node.ssl ? 0 : 1;
	int cache = node.cache ? 0 : 1;
	snprintf(sql, sizeof(sql), "INSERT INTO main.node VALUES(null, '%s', '%s', %d, %d, %d, '%s', %.6f, '%s');",
			 node.name, node.domain, node.port, ssl, cache, node.version, node.fee, node.proxy_url);

	int txn_prepared = db_transaction_prepared(db_name, sql, db_password);

	if (txn_prepared != 0)
	{
	  	//TODO: remove print statement later or switch to logging framework
		log_error("Add node failed!");
	  	return 1;
	}

	return 0;
}

int db_add_node_initial_data(const char **db_name, const char *db_password)
{
	node_t node_list[13] = {
		{ "Swepool", 				"swepool.org",			11898,false,false,"1.1.0",0.00,"swepool" },
		{ "Göta Pool",			"gota.kryptokrona.se",	11898,false,false,"1.1.0",0.00,"gota" },
		{ "Blocksum",				"blocksum.org",			11898,false,false,"1.1.0",0.00,"blocksum" },
		{ "Gamersnest",			"pool.gamersnest.org",	11898,true, false,"1.1.0",0.00,"gamersnest" },
		{ "Norpool",				"norpool.org",			11898,false,false,"1.1.0",0.00,"norpool" },
		{ "Privacy Mine",			"privacymine.net",		11898,false,false,"1.1.0",0.00,"privacymine" },
		{ "Privacy Mine SSL",		"privacymine.net",		21898,true, false,"1.1.0",0.00,"privacymine" },
		{ "KuKoHumoR",			"kukohumor.se",			11898,false,false,"1.1.0",0.00,"KuKoHumoR" },
		{ "Spider Pig",			"spider-pig.hopto.org",	11898,false,false,"1.1.0",0.00,"spider-pig" },
		{ "TechyNode",			"129.153.157.185",		11898,false,false,"1.1.0",0.00,"TechyNode" },
		{ "TechyNode-Backup",	"techy.ddns.net",		11898,false,false,"1.1.0",0.00,"TechyNode-Backup" },
		{ "Wasa",				"wasa.kryptokrona.se",	11898,false,false,"1.1.0",0.00,"wasa" },
		{ "Tifo",				"tifo.info",			11898,false,false,"1.1.0",0.00,"blocksum" },
	};

	for (int n = 0; n < 13; n++)
	{
	  	db_add_node(db_name, node_list[n], db_password);
	}

	return 0;
}