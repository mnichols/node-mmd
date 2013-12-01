# MultiMarkdown for node


## Goals

* Expose [MultiMarkdown](https://github.com/fletcher/MultiMarkdown-4) to node in a friendlier API.

## Support for

* ~~Convert to HTML~~
* ~~Extract metadata value(s)~~
* ~~Extract metadata key(s)~~


## Usage

//TODO...finishing up bindings ATM

## API

### mmd.convert(source,[options])

* `source` {String} The content of the markdown
* `options` {Object}

### Options

* `full` {Boolean} Whether to generate a full html document or not. Default is `false`.
* `format` {String} One of the supported formats:
    * html
    * odf
    * rtf
    * text
    * latex (TODO...not supported atm)

