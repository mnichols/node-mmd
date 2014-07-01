#ifndef __EXTENSIONS_H_INCLUDED__
#define __EXTENSIONS_H_INCLUDED__

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
    EXT_NO_METADATA     = 1 << 10,   /* Don't parse Metadata */
    EXT_OBFUSCATE       = 1 << 11,   /* Mask email addresses */
    EXT_CRITIC          = 1 << 12,   /* Critic Markup Support */
    EXT_CRITIC_ACCEPT   = 1 << 13,   /* Accept all proposed changes */
    EXT_CRITIC_REJECT   = 1 << 14,   /* Reject all proposed changes */
    EXT_RANDOM_FOOT     = 1 << 15,   /* Use random numbers for footnote links */
    EXT_FAKE            = 1 << 31,   /* 31 is highest number allowed */
};

#endif //__EXTENSIONS_H_INCLUDED__
