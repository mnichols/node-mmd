#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>
/* These are the basic extensions */
enum parser_extensions {
        EXT_COMPATIBILITY   = 1 << 0,    /* Markdown compatibility mode */
        EXT_COMPLETE        = 1 << 1,    /* Create complete document */
        EXT_SNIPPET         = 1 << 2,    /* Create snippet only */
        EXT_HEAD_CLOSED     = 1 << 3,    /* for use by parser */
        EXT_SMART           = 1 << 4,    /* Enable Smart quotes */
        EXT_NOTES           = 1 << 5,    /* Enable Footnotes */
        EXT_NO_LABELS       = 1 << 6,    /* Don't add anchors to headers, etc. */
        EXT_FILTER_STYLES   = 1 << 7,    /* Filter out style blocks */
        EXT_FILTER_HTML     = 1 << 8,    /* Filter out raw HTML */
        EXT_PROCESS_HTML    = 1 << 9,    /* Process Markdown inside HTML */
        EXT_NO_METADATA     = 1 << 10,    /* Don't parse Metadata */
        EXT_OBFUSCATE       = 1 << 11,   /* Mask email addresses */
        EXT_CRITIC          = 1 << 12,   /* Critic Markup Support */
        EXT_CRITIC_ACCEPT   = 1 << 13,   /* Accept all proposed changes */
        EXT_CRITIC_REJECT   = 1 << 14,   /* Reject all proposed changes */
        EXT_FAKE            = 1 << 15,   /* 15 is highest number allowed */
};

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
    char * markdown_to_string(char *text, int extensions, int output_format);
}

using namespace v8;

// Configuration
int format = HTML_FORMAT;
int extensions = EXT_SMART | EXT_NOTES | EXT_SNIPPET;

Handle<Value> convert(const Arguments& args) {
    HandleScope scope;

    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
        return scope.Close(Undefined());
    }

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

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("convert"),
            FunctionTemplate::New(convert)->GetFunction());
}


NODE_MODULE(multimarkdown, init)
