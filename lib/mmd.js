'use strict';


var mmd = require(__dirname, '/../build/Release/multimarkdown.node');

module.exports.convert = mmd.convert
module.exports.extractMetadataValue = mmd.extract_metadata_value
module.exports.extractMetadataKeys = mmd.extract_metadata_keys
