all: clean deps

clean:
	rm -rf build
	rm -rf deps

deps: clean
	npm install

dev-compile:
	./node_modules/.bin/node-gyp configure --debug
	./node_modules/.bin/node-gyp build --debug

test: dev-compile
	./node_modules/mocha/bin/mocha

.PHONY: test clean install compile
