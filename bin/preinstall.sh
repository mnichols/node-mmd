#!/usr/bin/env bash

node-gyp configure
mkdir -p deps
cd deps
#curl -L https://github.com/fletcher/Multimarkdown-4/tarball/4.4.2 | tar zxvf -
#mv fletcher* MultiMarkdown-4
git clone -b "4.4.2" https://github.com/fletcher/MultiMarkdown-4.git
cd MultiMarkdown-4
git submodule init
git submodule update
cd greg
#sidestep a build err that occurs with greg sometimes
#(see fletcher notes on building MMD)
touch greg.c
# build Multimarkdown-4
cd .. && make
#CFLAGS='-fPIC -Wall -O3 -include GLibFacade.h -include parser.h -I ./ -D MD_USE_GET_OPT=1 -D_GNU_SOURCE' make
cd ../../ && node-gyp build
