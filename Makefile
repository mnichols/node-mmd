all: clean install

clean:
	rm -rf build
	rm -rf deps

install: clean
	npm install

dev-compile:
	./node_modules/.bin/node-gyp configure --debug
	./node_modules/.bin/node-gyp build --debug

test: install
	./node_modules/mocha/bin/mocha

.PHONY: test clean install compile
