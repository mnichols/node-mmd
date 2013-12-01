'use strict';
describe('when extracting metadata keys',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
        ,fs = require('fs')
        ,path = require('path')
        ;
    it('should return an array of keys',function(){
        var file = path.resolve(__dirname,'simple-annotated.md')
        var source = fs.readFileSync(file,{encoding:'utf-8'})
        var keys = mmd.extractMetadataKeys(source)
        keys.length.should.equal(3)
        keys.should.eql([
            'title'
            ,'author'
            ,'date'
        ])
    })

})

