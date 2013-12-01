#include <node.h>
#include <v8.h>


//multimarkdown ops
#include "convert.hpp"
#include "extract-metadata-value.hpp"
#include "extract-metadata-keys.hpp"

using namespace v8;

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("convert"),
            FunctionTemplate::New(Convert)->GetFunction());

    target->Set(String::NewSymbol("extractMetadataKeys"),
            FunctionTemplate::New(ExtractMetadataKeys)->GetFunction());

    target->Set(String::NewSymbol("extractMetadataValue"),
            FunctionTemplate::New(ExtractMetadataValue)->GetFunction());
}


NODE_MODULE(mmd, init)
