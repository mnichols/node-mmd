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
    char * extract_metadata_keys(char *text,unsigned long extensions);
}

using namespace v8;
using namespace std;


NAN_METHOD(ExtractMetadataKeys) {
    NanScope();

    //uses v8::Value::IsString() method to determine if the arg is an string
    if(args.Length() < 1 || !args[0]->IsString()) {
        return NanThrowError("Must pass file path as first argument");
    }

    //A Local<T> type of Handle<T>; contrasted to a Persistent<T> Handle
    //Calls v8::Value::ToString(), returning an Local<String>
    v8::Local<v8::String> ls = args[0]->ToString();

    int stringLen = ls->Utf8Length();

    // Allocate memory for input string
    char *buf = (char*) malloc(stringLen + 1);
    memset(buf, 0, stringLen + 1);
    ls->WriteUtf8(buf, stringLen, NULL, 0);

    // Convert to keys list
    char *out = extract_metadata_keys(buf, EXT_SMART | EXT_NOTES);
    free(buf);

    v8::Handle<v8::Array> result = Arrayed(out);
    free(out);

    NanReturnValue(result);

}

