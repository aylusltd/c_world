#include <iostream>
#include <string>
#include <vector>
#include <sys/ioctl.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

struct padding{
    int left;
    int right;
};

std::vector<int> makeSieve(unsigned long int len){
    std::vector<int> primes;
    unsigned long int* sieve = new unsigned long int[len];
    cout<<"Made array"<<endl;
    unsigned long int divisor;
    unsigned long int addressToRemove;
    long double maxTest = sqrt(len);
    for(unsigned long int i=1; i<=len; i++){
        primes.push_back(i);
        sieve[i-1]=i;
    }
    cout<<"Populated array"<<endl;
    for(unsigned long int i=1; i<len-1; i++){
        divisor = sieve[i];
        for(unsigned long int j=2; j<maxTest; j++){
            try{
                addressToRemove = (divisor*j)-1;
            } catch (int i){
                addressToRemove = len;
            }
            // if(addressToRemove > 2147488281){
            //     cout<<addressToRemove<<endl;
            // }
            if(addressToRemove < len){
                if(primes[addressToRemove] % divisor ==0){
                    primes[addressToRemove] = 0;    
                }
            }
        }
    }

    return primes;
}

void printPrimes(vector<int> primes, bool lineBreak){
    int linePos=0;
    int futurePos=0;
    string nextPrint;
    int maxPos;
    //TO DO Make const;
    const padding PADDING = {5, 10};
    // PADDING.left = 2;
    // PADDING.right = 10;
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    maxPos = w.ws_col - PADDING.right - PADDING.left;
    bool needsBreak = false;

    for(int i=0; i<primes.size(); i++){
        if(primes[i]){
            nextPrint="";
            if(i>0 && primes[i]){
                cout<<", ";
                linePos+=2;
            }
            if(needsBreak && lineBreak){
                cout<<endl;
                needsBreak = false;
                linePos=0;
            }
            futurePos=linePos;
            nextPrint+=to_string(primes[i]);
            futurePos+=nextPrint.length();
            if(futurePos > maxPos){
                needsBreak = true;
            } else {
                linePos = futurePos;
            }
            cout<<nextPrint;
        }
    }
    cout<<endl;
}

void printPrimes(vector<int> primes){
    printPrimes(primes, true);
}

void save(vector<int> primes, char* filename){
    fstream myfile;
    myfile.open(filename, ios::out);
    for(int i=0; i<primes.size(); i++){
        if(primes[i]){
            if(i>0 && primes[i]){
                myfile<<", ";
            }
            myfile<<primes[i];
        }
    }
    myfile.close();
}

int main(int argc, char *argv[]){
    unsigned long int len;
    const char* strongTypesSuck = argv[1];
    if(argc == 1){
        cout<<"Show primes less than?"<<endl;
        cin>>len;
    } else {
        len = stoi(strongTypesSuck);
    }
    
    std::vector<int> sieve = makeSieve(len);
    if(argv[2] && strncmp(argv[2],"-",1)!=0){
        save(sieve, argv[2]);
    } else if(argv[2]){
        printPrimes(sieve,false);
    } else {
        printPrimes(sieve);    
    }
    
    return 0;
}