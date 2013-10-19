all: clean
	npm install

clean:
	rm -rf build
	rm -rf deps

test:
	./node_modules/mocha/bin/mocha
.PHONY: test clean
