{
    "targets": [
        {
            "target_name": "multimarkdown",
            "sources":[ "multimarkdown.cc"],
            "link_settings": {
                "libraries":[
                    "../deps/MultiMarkdown-4/multimarkdown.o",
                    "../deps/MultiMarkdown-4/parser.o",
                    "../deps/MultiMarkdown-4/html.o",
                    "../deps/MultiMarkdown-4/GLibFacade.o"
                ]
            }
        }
    
    ]
}
