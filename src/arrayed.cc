#include <v8.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>


using namespace v8;

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        //note that we trim leading and tailing whitespace
        //for all items
        //to accomodate suggested \s\s in metadata
        elems.push_back(trim(item));
    }
    return elems;
}

/**
 * http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
 * **/
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


Handle<Array> Arrayed(char *source, char delimiter='\n' ) {
    if(!source) {
        return v8::Array::New(0);
    }
    // Convert to V8 string
    std::vector<std::string> arr = split(source,delimiter);
    v8::Handle<v8::Array> result = v8::Array::New(arr.size());
    for (size_t i = 0; i < arr.size(); i++) {
        result->Set(Number::New(i),String::New(&arr[i][0], arr[i].size()));
    }
    arr.clear();
    return result;
}
