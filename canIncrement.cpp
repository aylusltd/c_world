#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdlib.h>
#include "version.hpp"

using namespace std;

int main(int argc, char *argv[]){
    char *fromString = argv[1];
    char *toString = argv[2];
    int components[3];
    version::version from(fromString);
    version::version to(toString);
    int retCode = 0;

    // cout<<"From:"<<endl;
    // from.prettyPrint();

    // cout<<"To:"<<endl;
    // to.prettyPrint();

    if(!(to > from)){
        cerr<<"Cannot upgrade from "<<from.toString()<<" to "<<to.toString()<<"."<<endl;
        cerr<<"Semantic version must always increase."<<endl;
        cerr<<"Next release must be at least version ";
        cerr<<from.increment("release").toString()<<"."<<endl;
        retCode = 1;
    }

    return retCode;
}