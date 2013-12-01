'use strict';
describe('when converting to html fully',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
        ,fs = require('fs')
        ,path = require('path')
        ;
    it('should be a full doc',function(){
        var source  = fs.readFileSync(path.resolve(__dirname,'simple.md'),{
            encoding: 'utf-8'
        })
        var out = mmd.convert(source,{
            full: true
            ,format: 'html'
        })
        out.should.contain('<!DOCTYPE')
        out.should.contain('<html>')
        out.should.contain('<body>')


    })
    it('should work on annotated',function(){
        var expect  = {
            'aabb':'<p>aabb</p>'
        }
        for(var input in expect) {
            if(expect.hasOwnProperty(input)){
                var out = mmd.convert(input)
                out.should.equal(expect[input])
            }
        }

    })

})
describe('when converting to html snippets',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
        ,fs = require('fs')
        ,path = require('path')
        ;
    it('should convert simple',function(){
        var expect  = {
            'aabb':'<p>aabb</p>'
            ,'#Here is something\n\nSome Content':'<h1 id="hereissomething">Here is something</h1>\n\n<p>Some Content</p>'
        }
        for(var input in expect) {
            if(expect.hasOwnProperty(input)){
                var out = mmd.convert(input)
                out.should.equal(expect[input])
            }
        }

    })
    it('should work on annotated',function(){
        var expect  = {
            'aabb':'<p>aabb</p>'
        }
        for(var input in expect) {
            if(expect.hasOwnProperty(input)){
                var out = mmd.convert(input)
                out.should.equal(expect[input])
            }
        }

    })

})
