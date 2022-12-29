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

#include "node.h"

#include <sstream>
namespace core
{
Node::Node(std::string name,
		   std::string domain,
		   uint16_t port,
		   bool ssl,
		   bool cache,
		   std::string version,
		   double fee,
		   std::string proxy_url)
{
	m_name = name;
	m_domain = domain;
	m_port = port;
	m_ssl = ssl;
	m_cache = cache;
	m_version = version;
	m_fee = fee;
	m_proxy_url = proxy_url;
}

std::string Node::get_name()
{
	return m_name;
}

uint16_t Node::get_port()
{
	return m_port;
}

bool Node::ssl()
{
	return m_ssl;
}

bool Node::cache()
{
	return m_cache;
}

std::string Node::get_version()
{
	return m_version;
}

double Node::get_fee()
{
	return m_fee;
}

std::string Node::get_proxy_url()
{
	return m_proxy_url;
}
}