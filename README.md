# MultiMarkdown for node


## Goals

* Expose [MultiMarkdown](https://github.com/fletcher/MultiMarkdown-4) to node.

## Support for

* ~~Convert to HTML~~
* ~~Convert to ODF~~
* ~~Convert to Text~~
* ~~Convert to RTF~~
* Convert to Latex (TODO)
* ~~Extract metadata value(s)~~
* ~~Extract metadata key(s)~~


## API

This is a low-level, 1-to-1 match of the MultiMarkdown-4 API.
As such, there are no convenience methods for metadata, nor any
I/O concerns.

### mmd.convert(source,[options])

* `source` {String} The content of the markdown
* `options` {Object}

### Options

* `full` {Boolean} Whether to generate a full html document or not. Default is `false`.
* `format` {String} One of the supported formats (Default is `html`):
    * html
    * odf
    * rtf
    * text
    * latex (TODO...not supported atm)

### mmd.extract_metadata_value(source,key)

* `source` {String} The content of the markdown
* `key` {String} The metadata key to return
* `return` {Array} The value(s) mapped to the metadata key.
    * If the key does not exist, an empty array `[]` is returned.

### mmd.extract_metadata_keys(source)

* `source` {String} The content of the markdown
* `return` {Array} The keys for any metadata in the document.
    * If the document does not contain metadata, an empty array `[]` is returned.


