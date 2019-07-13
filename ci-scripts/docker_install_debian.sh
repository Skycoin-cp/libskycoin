#!/usr/bin/env bash

set -ex

apt update

apt install gcc g++ wget make cmake libcurl3-gnutls -y --allow

wget -c https://github.com/libcheck/check/releases/download/0.12.0/check-0.12.0.tar.gz
tar -xzf check-0.12.0.tar.gz
cd check-0.12.0 && ./configure --prefix=/usr --disable-static && make && sudo make install

wget -c http://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xvf curl-7.58.0.tar.gz
cd curl-7.58.0/ && make && sudo make install