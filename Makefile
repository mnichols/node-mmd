all: clean
	npm install

clean:
	rm -rf build
	rm -rf deps

compile:
	./node_modules/.bin/node-gyp build

test:
	./node_modules/mocha/bin/mocha
.PHONY: test clean compile
