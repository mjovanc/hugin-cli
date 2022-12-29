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

#include <sstream>
#include <string>
#include <vector>

#include "core/core.h"
#include "core/log.h"
#include "core/node.h"
#include "transaction.h"

namespace db
{
int db_add_node(const std::string db_name, core::Node node, const std::string db_password)
{
	std::stringstream sql;
	sql << "INSERT INTO main.node VALUES(null, "
		<< node.get_name()
		<< ", "
		<< node.get_domain()
		<< ", "
		<< node.get_port()
		<< ", "
		<< node.ssl()
		<< ", "
		<< node.get_version()
		<< ", "
		<< node.get_fee()
		<< ", "
		<< node.get_proxy_url()
		<< ");";

	int txn_prepared = db_transaction_prepared(db_name, sql.str(), db_password);

	if (txn_prepared != 0) {
		// TODO: log to file
		// log_error("Add node failed!");
		return 1;
	}

	return 0;
}

int db_add_node_initial_data(const std::string db_name, const std::string db_password)
{
	std::vector<core::Node> nodes = {
		core::Node("Swepool", "swepool.org", 11898, false, false, "1.1.0", 0.00, "swepool"),
		core::Node("Göta Pool", "gota.kryptokrona.se", 11898, false, false, "1.1.0", 0.00, "gota"),
		core::Node("Blocksum", "blocksum.org", 11898, false, false, "1.1.0", 0.00, "blocksum"),
		core::Node("Gamersnest", "pool.gamersnest.org", 11898, true, false, "1.1.0", 0.00, "gamersnest"),
		core::Node("Norpool", "norpool.org", 11898, false, false, "1.1.0", 0.00, "norpool"),
		core::Node("Privacy Mine", "privacymine.net", 11898, false, false, "1.1.0", 0.00, "privacymine"),
		core::Node("Privacy Mine SSL", "privacymine.net", 21898, true, false, "1.1.0", 0.00, "privacymine"),
		core::Node("KuKoHumoR", "kukohumor.se", 11898, false, false, "1.1.0", 0.00, "KuKoHumoR"),
		core::Node("Spider Pig", "spider-pig.hopto.org", 11898, false, false, "1.1.0", 0.00, "spider-pig"),
		core::Node("TechyNode", "129.153.157.185", 11898, false, false, "1.1.0", 0.00, "TechyNode"),
		core::Node("TechyNode-Backup", "techy.ddns.net", 11898, false, false, "1.1.0", 0.00, "TechyNode-Backup"),
		core::Node("Wasa", "wasa.kryptokrona.se", 11898, false, false, "1.1.0", 0.00, "wasa"),
		core::Node("Tifo", "tifo.info", 11898, false, false, "1.1.0", 0.00, "blocksum"),
	};

	for (unsigned int n = 0; n < nodes.size(); n++) {
		db_add_node(db_name, nodes[n], db_password);
	}

	return 0;
}
}