#!/usr/bin/env bash

node-gyp configure --debug
mkdir -p deps
cd deps
git clone https://github.com/fletcher/MultiMarkdown-4.git
cd MultiMarkdown-4
git submodule init
git submodule update
#curl 'https://codeload.github.com/fletcher/MultiMarkdown-4/tar.gz/4.3.2' | tar zxvf - 
#mv MultiMarkdown-4-* MultiMarkdown-4
cd greg
#sidestep a build err that occurs with greg sometimes
#(see fletcher notes on building MMD)
touch greg.c
# build Multimarkdown-4
cd .. && make
#CFLAGS='-fPIC -Wall -O3 -include GLibFacade.h -include parser.h -I ./ -D MD_USE_GET_OPT=1 -D_GNU_SOURCE' make
cd ../../ && node-gyp build --debug
