#include <node.h>
#include <v8.h>

using namespace v8;

extern "C" {
    char * markdown_to_string(char *text, int extensions, int output_format);
}

Handle<Value> convertToHtml(const Arguments& args) {

}

