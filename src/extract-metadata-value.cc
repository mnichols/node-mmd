#include <node.h>
#include <nan.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

#include "extensions.hpp"
#include "arrayed.hpp"

extern "C" {
    char * extract_metadata_value(char *source, unsigned long extensions, char *key);
}

using namespace v8;
using namespace std;

/**
 * Handle<T> is a v8 Class Template reference
 * ;an abstract class
 * */
NAN_METHOD(ExtractMetadataValue) {
    NanScope();
    int extensions = EXT_SMART | EXT_NOTES | EXT_SNIPPET;

    //expects the _source_ as the first arg

    //uses v8::Value::IsString() method to determine if the arg is an string
    if(args.Length() < 1 || !args[0]->IsString()) {
        return NanThrowError("Must pass string as first argument");
    }
    //uses v8::Value::IsString() method to determine if the arg is an string
    if(args.Length() < 1 || !args[1]->IsString()) {
        return NanThrowError("Must pass string as second argument");
    }


    //The source content (markdown) from args[0]
    v8::Local<v8::String> ls = args[0]->ToString();
    int stringLen = ls->Utf8Length();
    char *buf = (char*) malloc(stringLen + 1);
    memset(buf, 0, stringLen + 1);
    ls->WriteUtf8(buf, stringLen, NULL, 0);

    //The metadata key from args[1]
    v8::Local<v8::String> ks = args[1]->ToString();
    int keyLen = ks->Utf8Length();
    char *key = (char*) malloc(keyLen + 1);
    memset(key, 0, keyLen + 1);
    ks->WriteUtf8(key, keyLen, NULL, 0);

    // Convert to keys list
    //unsigned long ext = 2096; //multimarkdown command line has this value
    char *out = extract_metadata_value(buf, extensions, key);
    free(buf);
    free(key);
    if(!out) {
        //the key either doesnt exist or is empty
        //so just return empty array
        free(out);
        NanReturnValue(NanNew<v8::Array>(0));
    }
    v8::Handle<v8::Array> arr = Arrayed(out);
    free(out);

    NanReturnValue(arr);
}


