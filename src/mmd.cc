#include <node.h>
#include <nan.h>
#include <v8.h>


//multimarkdown ops
#include "convert.hpp"
#include "extract-metadata-value.hpp"
#include "extract-metadata-keys.hpp"


void init(v8::Handle<v8::Object> target) {
    target->Set(NanNew<v8::String>("convert"),
            NanNew<v8::FunctionTemplate>(Convert)->GetFunction());

    target->Set(NanNew<v8::String>("extractMetadataKeys"),
            NanNew<v8::FunctionTemplate>(ExtractMetadataKeys)->GetFunction());

    target->Set(NanNew<v8::String>("extractMetadataValue"),
            NanNew<v8::FunctionTemplate>(ExtractMetadataValue)->GetFunction());
}


NODE_MODULE(mmd, init)
