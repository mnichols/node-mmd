#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

#include "extensions.hpp"

extern "C" {
    char * extract_metadata_keys(char *text,unsigned long extensions);
}

using namespace v8;
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

/**
 * http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
 * **/
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

Handle<Value> ExtractMetadataKeys(const Arguments& args) {
    HandleScope scope;
    int extensions = EXT_SMART | EXT_NOTES | EXT_SNIPPET;
    //uses v8::Value::IsString() method to determine if the arg is an string
    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass file path as first argument")));
        return scope.Close(Undefined());
    }

    //A Local<T> type of Handle<T>; contrasted to a Persistent<T> Handle
    //Calls v8::Value::ToString(), returning an Local<String>
    Local<String> ls = args[0]->ToString();

    int stringLen = ls->Utf8Length();

    // Allocate memory for input string
    char *buf = (char*) malloc(stringLen + 1);
    memset(buf, 0, stringLen + 1);
    ls->WriteUtf8(buf, stringLen, NULL, 0);

    // Convert to keys list
    char *out = extract_metadata_keys(buf, EXT_SMART | EXT_NOTES);
    free(buf);

    // Convert to V8 string
    std::vector<std::string> arr = split(out,'\n');
    free(out);
    v8::Handle<v8::Array> result = v8::Array::New(arr.size());
    for (size_t i = 0; i < arr.size(); i++) {
      result->Set(Number::New(i),String::New(&arr[i][0], arr[i].size()));
    }
    arr.clear();

    return scope.Close(result);



}

