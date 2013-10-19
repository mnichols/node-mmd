'use strict';
describe('when converting to html',function(){
    var mmd = require('../build/Release/multimarkdown.node')
    it('should work',function(){
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
