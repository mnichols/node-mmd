BUILD       = build
MMD_DIR     = deps/MultiMarkdown-4
MMD_OBJECTS = $(MMD_DIR)/multimarkdown.o
TARGET      = $(BUILD)/Release/mmd.node
TARGET     += $(BUILD)/Debug/mmd.node
NODE_GYP    = ./node_modules/.bin/node-gyp

all: clean $(TARGET)

preinstall: $(TARGET)

multimarkdown: $(MMD_OBJECTS)

$(MMD_OBJECTS):
	./bin/compile-multimarkdown.sh

$(TARGET): $(BUILD) $(MMD_OBJECTS) $(NODE_GYP)
	./node_modules/.bin/node-gyp configure --debug
	./node_modules/.bin/node-gyp build --debug
	./node_modules/.bin/node-gyp configure
	./node_modules/.bin/node-gyp build

$(BUILD):
	@mkdir -p $@

$(NODE_GYP):
	npm install nan
	npm install node-gyp

clean:
	rm -rf build
	rm -rf deps

node_modules: package.json
	npm install

test: $(TARGET) node_modules
	./node_modules/mocha/bin/mocha

.PHONY: test clean preinstall debug
