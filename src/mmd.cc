#include <node.h>
#include <nan.h>
#include <v8.h>


//multimarkdown ops
#include "convert.hpp"
#include "extract-metadata-value.hpp"
#include "extract-metadata-keys.hpp"


void init(v8::Handle<v8::Object> target) {
    Nan::HandleScope scope;
    Nan::SetMethod(target, "convert", Convert);
    Nan::SetMethod(target, "extractMetadataKeys", ExtractMetadataKeys);
    Nan::SetMethod(target, "extractMetadataValue", ExtractMetadataValue);
}


NODE_MODULE(mmd, init)
