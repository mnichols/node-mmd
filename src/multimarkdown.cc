#include <node.h>
#include <v8.h>


//multimarkdown ops
#include "convert.hpp"
#include "extract-metadata-value.hpp"
#include "extract-metadata-keys.hpp"

using namespace v8;
using namespace std;



/*
Handle<Value> setFormat(const Arguments& args) {
    HandleScope scope;

    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
        return scope.Close(Undefined());
    }

    char argbuf[10];
    Local<String> s = args[0]->ToString();
    s->WriteUtf8(argbuf, 10, NULL, 0);
    if(strcmp("latex", argbuf) == 0) {
        format = LATEX_FORMAT;
    }
    else {
        format = HTML_FORMAT;
    }
}
*/

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("convert"),
            FunctionTemplate::New(Convert)->GetFunction());

    target->Set(String::NewSymbol("extractMetadataKeys"),
            FunctionTemplate::New(ExtractMetadataKeys)->GetFunction());

    target->Set(String::NewSymbol("extractMetadataValue"),
            FunctionTemplate::New(ExtractMetadataValue)->GetFunction());
}


NODE_MODULE(multimarkdown, init)
