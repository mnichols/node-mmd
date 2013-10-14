all: clean
	npm install

clean:
	rm -rf build
	rm -rf deps

.PHONY: test clean
