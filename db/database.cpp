// Copyright (c) 2022-2022, The Kryptokrona Project
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

#include <iostream> 

#include "db/sqlite3.h"
#include "database.h"

namespace db
{
	Database::Database()
	{
	}

    Database::~Database()
    {
    }

    int Database::open()
    {
        // pointer to SQLite connection
        sqlite3* db;

        // this didn't work properly (it didn't save a database before)
        // std::stringstream ss;
        // ss << dbName << ".db";
        // std::string fileName = ss.str();

        // const char* fileNameArr = new char[fileName.length()+1];
        
        // save the connection result
        int exit = 0;
        exit = sqlite3_open("change_this_later.db", &db); 
    
        // test if there was an error
        // we should probably use a logging framework instead so the user will not see these
        if (exit) { 
            std::cout << "DB Open Error: " << sqlite3_errmsg(db) << std::endl; 
        } else {
            std::cout << "Opened Database Successfully!" << std::endl; 
        }
        
        // close the connection
        sqlite3_close(db); 
        
        return (0); 
    }
}