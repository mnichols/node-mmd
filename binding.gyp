{
    "targets": [
        {
            "target_name": "multimarkdown",
            "sources":[ "multimarkdown.cc"],
            "link_settings": {
                "libraries":[
                    "../deps/MultiMarkdown-4/multimarkdown.o",
                    "../deps/MultiMarkdown-4/parse_utilities.o",
                    "../deps/MultiMarkdown-4/parser.o",
                    "../deps/MultiMarkdown-4/GLibFacade.o",
                    "../deps/MultiMarkdown-4/writer.o",
                    "../deps/MultiMarkdown-4/text.o",
                    "../deps/MultiMarkdown-4/html.o",
                    "../deps/MultiMarkdown-4/latex.o",
                    "../deps/MultiMarkdown-4/memoir.o",
                    "../deps/MultiMarkdown-4/beamer.o",
                    "../deps/MultiMarkdown-4/opml.o",
                    "../deps/MultiMarkdown-4/odf.o",
                    "../deps/MultiMarkdown-4/critic.o"

                ]
            }
        }
    
    ]
}
