#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "file_mod_bin.hpp"

using namespace std;

void err(string text){
    cerr<<"\033[1;31m";
    cerr<<text;
    cerr<<"\033[0m";
    cerr<<endl;
}

void err(BYTE text){
    cerr<<"\033[1;31m";
    cerr<<text;
    cerr<<"\033[0m";
}

BYTE calcDistance(vector<BYTE> key){
    BYTE distance=0;
    unsigned long int l = key.size();
    for(unsigned long int i=0; i<l; i++){
        distance+=key[i];
    }
    return distance;
}

vector<BYTE> shuffleBytes(std::vector<BYTE> input, BYTE distance){
    vector<BYTE> temp=input;
    unsigned long int t;
    unsigned long int j = input.size();
    unsigned long int i;
    BYTE d=distance;
    // Rotate
    for(i=0; i<j; i++){
        t=(i+distance)%j;
        temp[t]=input[i];
    }

    input=temp;

    // Mix
    // d=4; 
    // t[3]=i[0];
    // t[2]=i[1];
    // t[1]=i[2];
    // t[0]=i[3];
    // t[7]=i[4];
    // t[6]=i[5];
    for(i=0; i<j; i++){
        t=(d-i%d) + ((i/d)*d) - 1;
        temp[t]=input[i];
    }
    input=temp;
    
    return input;
}

vector<BYTE> unshuffle(std::vector<BYTE> input, BYTE distance){
    vector<BYTE> temp=input;
    unsigned long int t;
    unsigned long int j = input.size();
    unsigned long int i;
    BYTE d=distance;

    // Unmix (should be symmetrical?)
    for(i=0; i<j; i++){
        t=(d-i%d) + ((i/d)*d) - 1;
        temp[t]=input[i];
    }
    input = temp;
    
    // Unrotate
    for(i=0; i<j; i++){
        t=i<distance?j-distance+i+1:(i-distance)%j;
        temp[t]=input[i];
    }
    input=temp;

    
    
    return input;
}

vector<BYTE> encrypt(vector<BYTE> input, vector<BYTE> key){
    err("encrypting");
    unsigned long int j = input.size();
    unsigned long int k = key.size();
    BYTE distance = calcDistance(key);

    err("input length: "+to_string(j));
    err("key length: "+to_string(k));
    unsigned long int t;

    // Modify
    for(unsigned long int i=0; i<j; i++){
        input[i]+= key[i%k];
        // err(input[i]);
        // err(key[i%k]);
        // err(to_string(i%k));
        // err(" ");
    }
    // cerr<<endl;

    // Shuffle
    input = shuffleBytes(input, distance);
    
    return input;
}

vector<BYTE> decrypt(std::vector<BYTE> input, std::vector<BYTE> key){
    err("Decrypting");
    unsigned long int j = input.size();
    unsigned long int k = key.size();
    err("j: " + to_string(j));
    err("k: " + to_string(k));
    unsigned long int t;

    // unshuffle
    input=unshuffle(input,calcDistance(key));

    // unmutate
    for(unsigned long int i=0; i<j; i++){
        input[i]-= key[i%k];
        // err(key[i%k]);
        // err(to_string(i%k));
        // err(" ");
        // err(input[i]);
    }
    // cerr<<endl;
    
    return input;
}

bool sc(string a, string b){
    return a.compare(b) ==0;
}

int main(int argc, char *argv[]){
    string keyFile;
    string targetFile;
    string sourceFile;
    string arg;
    const string EFLAG="-e";
    const string DFLAG="-d";
    const string KFLAG="-k";
    const string TFLAG="-t";
    const string SFLAG="-s";
    const string ALT_TFLAG="-o";
    const string RFLAG= "-r";
    int rounds = 8;

    bool encrypting = false;

    for(int i=0; i<argc; i++){
        arg = (string) argv[i];
        if(sc(EFLAG,arg)){
            encrypting=true;
        }
        if(sc(DFLAG,arg)){
            encrypting|=false;
        }
        if(sc(KFLAG,arg)){
            keyFile=argv[i+1];
        }
        if(sc(TFLAG,arg) || sc(ALT_TFLAG,arg)){
            targetFile=argv[i+1];
        }
        if(sc(arg,SFLAG)){
            sourceFile=argv[i+1];
        }
        if(sc(RFLAG, arg)){
            if(stoi(argv[i+1]) > rounds){
                rounds = stoi(argv[i+1]);
            }
        }
    }

    std::vector<BYTE> key = f::readFile(keyFile);
    std::vector<BYTE> source = f::readFile(sourceFile);
    std::vector<BYTE> output;

    if(encrypting){
        for(int i=0; i<rounds; i++){
            output=encrypt(source,key);
        }
    } else {
        for(int i=0; i<rounds; i++){
            output=decrypt(source, key);
        }
    }
    f::save(output, targetFile);

    return 0;
}