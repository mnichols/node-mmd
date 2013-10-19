#!/usr/bin/env bash

node-gyp configure
mkdir -p deps
cd deps
git clone https://github.com/fletcher/MultiMarkdown-4.git
cd MultiMarkdown-4
git submodule init
git submodule update
#curl 'https://codeload.github.com/fletcher/MultiMarkdown-4/tar.gz/4.3.2' | tar zxvf - 
#mv MultiMarkdown-4-* MultiMarkdown-4
cd greg
touch greg.c
cd ..
#CFLAGS='-fPIC -Wall -O3 -include GLibFacade.h -include parser.h -I ./ -D MD_USE_GET_OPT=1 -D_GNU_SOURCE' make
make
cd ../../ && node-gyp build
