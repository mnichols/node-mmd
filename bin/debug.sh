#!/usr/bin/env bash

node-gyp configure
cd deps
cd MultiMarkdown-4
cd greg
cd ..
make
cd ../../ && node-gyp build
