#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "extensions.hpp"

/* Define output formats we support -- first in list is default */
enum export_formats {
        HTML_FORMAT,
        TEXT_FORMAT,
        LATEX_FORMAT,
        MEMOIR_FORMAT,
        BEAMER_FORMAT,
        OPML_FORMAT,
        ODF_FORMAT,
        RTF_FORMAT,
        ORIGINAL_FORMAT,                 /* Not currently used */
        CRITIC_ACCEPT_FORMAT,
        CRITIC_REJECT_FORMAT,
        CRITIC_HTML_HIGHLIGHT_FORMAT,
};

extern "C" {
    char * markdown_to_string(char *text, unsigned long extensions, int output_format);
}

using namespace v8;
using namespace std;

/**
 * Handle<T> is a v8 Class Template reference
 * ;an abstract class
 * */
Handle<Value> Convert(const Arguments& args) {
    HandleScope scope;
    unsigned long extensions = EXT_SMART | EXT_NOTES | EXT_SNIPPET;
    int format = HTML_FORMAT;

    //uses v8::Value::IsString() method to determine if the arg is an string
    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
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

    // Convert to markdown
    char *out = markdown_to_string(buf, extensions, format);
    free(buf);

    // Convert to V8 string
    Local<String> outString = String::New(out);
    free(out);

    return scope.Close(outString);
}


