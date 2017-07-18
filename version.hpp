#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdlib.h>

namespace version{

    struct version{
        int major;
        int minor;
        int release;
        void prettyPrint(){
            std::cout<<"Major: "<<this->major<<std::endl;
            std::cout<<"Minor: "<<this->minor<<std::endl;
            std::cout<<"Release: "<<this->release<<std::endl;
        }
        void err(){
            std::cerr<<this->major<<"."<<this->minor<<"."<<this->release;
        }
        std::string toString(){
            std::string v="";
            v+=std::to_string(this->major);
            v+=".";
            v+=std::to_string(this->minor);
            v+=".";
            v+=std::to_string(this->release);
            return v;
        }
        version increment(std::string spot){
            int major = this->major;
            int minor = this->minor;
            int release = this->release;
            if(spot=="major"){
                major++;
            } else if(spot == "minor"){
                minor++;
            } else if(spot == "release"){
                release++;
            } else {
                std::cerr<<"Invalid argument passed to increment"<<std::endl;
                std::cerr<<"Must be either 'major', 'minor', or 'release'."<<std::endl;
                std::cerr<<"Received: "<<spot<<std::endl;
                exit (EXIT_FAILURE);            
            }
            version newV (major, minor, release);
            return newV;
        }
        version(std::string vString){
            int val;
            int *c = new int[3];
            // int i=0;
            std::regex re("([0-9]+)\\.([0-9]+)\\.([0-9]+)");
            std::smatch m;
            std::string piece;

            if (std::regex_search(vString, m, re)){
                for(int j=0;j<3;j++){
                    piece = m[j+1];
                    c[j]=std::stoi(piece);
                }
            }

            this->major=c[0];
            this->minor=c[1];
            this->release=c[2];
        }

        version(int major, int minor, int release){
            this->major=major;
            this->minor=minor;
            this->release=release;
        }
        bool isGreaterThan(version alt){
            if(this->major > alt.major){
                return true;
            } 
            if(alt.major > this->major){
                return false;
            }
            if(this->minor > alt.minor){
                return true;
            }
            if(alt.minor > this->minor) {
                return false;
            }
            if(this->release > alt.release){
                return true;
            }
            return false;
        }

    };

    version vParse(std::string vString){
        int val;
        int *c = new int[3];
        int i=0;
        std::regex re("([0-9]+)\\.([0-9]+)\\.([0-9]+)");
        std::smatch m;
        std::string piece;

        if (std::regex_search(vString, m, re)){
            for(int j=0;j<3;j++){
                piece = m[j+1];
                c[j]=std::stoi(piece);
            }
        }

        version v(c[0],c[1],c[2]);

        return v;
    }

    bool isGreater(version a, version b){
        if(a.major > b.major){
            return true;
        } 
        if(b.major > a.major){
            return false;
        }
        if(a.minor > b.minor){
            return true;
        }
        if(b.minor > a.minor) {
            return false;
        }
        if(a.release > b.release){
            return true;
        }
        return false;
    }
    inline bool operator< (version& lhs, version& rhs){ return rhs.isGreaterThan(lhs); }
    inline bool operator> (version& lhs, version& rhs){ return rhs < lhs; }
    inline bool operator<=(version& lhs, version& rhs){ return !(lhs > rhs); }
    inline bool operator>=(version& lhs, version& rhs){ return !(lhs < rhs); }

    inline bool operator==(version& lhs, version& rhs){
        bool isEqual=true;
        isEqual &= lhs.major==rhs.major;
        isEqual &= lhs.minor==rhs.minor;
        isEqual &= lhs.release==rhs.release; 
        return isEqual; 
    }
    inline bool operator!=(version& lhs, version& rhs){ return !(lhs == rhs); }

}