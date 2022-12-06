#!/bin/bash

# Copyright (c) 2022-2022, The Kryptokrona Project
#
# Created by Marcus Cvjeticanin
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are
# permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this list of
# conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice, this list
# of conditions and the following disclaimer in the documentation and/or other
# materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be
# used to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
# THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
# THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# constants
APP_NAME=hugin-cli
APP_BINARY=Hugin
APP_INSTALLATION_PATH=/opt/$APP_NAME

# create app dir
echo "Creating application directory..."
sudo mkdir -p $APP_INSTALLATION_PATH

# place icon and binary
echo "Placing icon in application directory..."
sudo cp resources/icon.png $APP_INSTALLATION_PATH/icon.png

echo "Setting permission for ${APP_INSTALLATION_PATH}/icon.png..."
chmod 644 $APP_INSTALLATION_PATH/icon.png

echo "Placing binary in application directory..."
sudo cp build/Hugin $APP_INSTALLATION_PATH/$APP_BINARY

echo "Setting executable permission for ${APP_BINARY}..."
sudo chmod +x $APP_INSTALLATION_PATH/$APP_BINARY

echo "Placing desktop icon..."
cp resources/$APP_NAME.desktop $HOME/.local/share/applications/$APP_NAME.desktop

echo "Setting executable permission for ${APP_NAME}.desktop..."
chmod +x $HOME/.local/share/applications/$APP_NAME.desktop

echo "${APP_BINARY} is now installed..."


