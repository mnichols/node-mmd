# MultiMarkdown for node

[![Build Status](https://travis-ci.org/mnichols/node-mmd.svg?branch=master)](https://travis-ci.org/mnichols/node-mmd)

## Goals

* Expose [MultiMarkdown](https://github.com/fletcher/MultiMarkdown-4) to node.

This addon is _usually_ revisioned in tandem with Fletcher's library.

## MultiMarkdown Support for

* ~~Convert to HTML~~
* ~~Convert to ODF~~
* ~~Convert to Text~~
* Convert to Latex (TODO)
* ~~Extract metadata value(s)~~
* ~~Extract metadata key(s)~~


## Usage

`npm install mmd`

```js
var mmd = require('mmd')
var html = mmd.convert('# Look Ma!')
```

## API

This is a low-level, 1-to-1 match of the MultiMarkdown-4 API.
As such, there are no convenience methods for metadata, nor any
I/O concerns.

### mmd.convert(source,[options])

* `source` {String} The content of the markdown
* `options` {Object}
* `return` {String} The converted document

### Options

* `full` {Boolean} Whether to generate a full html document or not. Default is `false`.
* `format` {String} One of the supported formats (Default is `html`):
    * html
    * odf
    * rtf
    * text
    * latex (TODO...not supported atm)

### mmd.extractMetadataValue(source,key)

* `source` {String} The content of the markdown
* `key` {String} The metadata key to return
* `return` {Array} The value(s) mapped to the metadata key.
    * If the key does not exist, an empty array `[]` is returned.

### mmd.extractMetadataKeys(source)

* `source` {String} The content of the markdown
* `return` {Array} The keys for any metadata in the document.
    * If the document does not contain metadata, an empty array `[]` is returned.

## CHANGELOG

* `4.7.1` using `nan` and bumped to fletcher's mmd 4.7.1 version
* `4.4.2` initial release with v4.4.2 of MultiMarkdown-4 bindings
* `4.4.3` minor notes
