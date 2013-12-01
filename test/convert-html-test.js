'use strict';
describe('when converting to html',function(){
    var mmd = require('../build/Debug/multimarkdown.node')
    it('should work',function(){
        var expect  = {
            'aabb':'<p>aabb</p>'
        }
        for(var input in expect) {
            if(expect.hasOwnProperty(input)){
                var out = mmd.convert(input)
                console.log('out',out)
                out.should.equal(expect[input])
            }
        }

    })

})
