'use strict';
describe('when extracting metadata keys',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
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
describe('when extracting metadata value',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
        ,fs = require('fs')
        ,path = require('path')
        ;
    it('should return value for present keys',function(){

        var file = path.resolve(__dirname,'simple2.md')
        var source = fs.readFileSync(file,{encoding:'utf-8'})
        var author = mmd.metadataValue(source,'author')
            ,title = mmd.metadataValue(source,'title')
            ;
        author.should.equal('mike')
        title.should.equal('Simple Annotated')

    })
    it('should return undefined for nonpresent keys',function(){

        var file = path.resolve(__dirname,'simple2.md')
        var source = fs.readFileSync(file,{encoding:'utf-8'})
        var nada = mmd.metadataValue(source,'nada')
            ;
        expect(nada).to.be.undefined

    })

})
