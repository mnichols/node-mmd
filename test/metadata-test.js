'use strict';
describe('when extracting metadata keys',function(){
    var mmd = require('../build/Release/multimarkdown.node')
        ,fs = require('fs')
        ,path = require('path')
        ;
    it('should return an array of keys',function(){
        var file = path.resolve(__dirname,'simple-annotated.md')
        var keys = mmd.metadataKeys(file)
        console.log('keys',keys)
        keys.length.should.equal(3)
    })

})
