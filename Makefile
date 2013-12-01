all: clean
	npm install

clean:
	rm -rf build
	rm -rf deps

dev-compile:
	./node_modules/.bin/node-gyp configure --debug
	./node_modules/.bin/node-gyp build --debug

test:
	./node_modules/mocha/bin/mocha

.PHONY: test clean compile
