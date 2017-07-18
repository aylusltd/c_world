#include <iostream>
#include <string>
#include <vector>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <fstream>

using namespace std;

bool isPrime(long n){
    double long s = sqrt(n);
    // cout<<s<<endl;
    int counter = 2;
    int original, sqrtv;
    original = (int) n;
    // cout<<counter<<endl;

    while(counter<=s){
        // cout<<counter<<endl;
        if(original % counter == 0){
            return false;
        } 
        counter++;
    }
    return true;
}

int main(int argc, char *argv[]){
    string lineInput;
    long n;
    int spaceVal = std::char_traits<char>::to_int_type(' ');
    int commaVal = std::char_traits<char>::to_int_type(',');
    int nextVal;
    int retVal = 0;
    bool t;

    if(argc == 1){
        while (cin >> n) {
            cout<<n<<" is ";
            if(!isPrime(n)){
                cout<<"NOT ";
            }
            cout<<"prime."<<endl;
            nextVal = cin.peek();
            if(nextVal == spaceVal || nextVal == commaVal ){
                cin>>lineInput;
            }
        }
    } else if(strncmp(argv[1],"-e",2)==0) {
        while (cin >> n) {
            if(!isPrime(n)){
                cerr<<n<<" is NOT prime."<<endl;
                retVal = 1;
            }
            nextVal = cin.peek();
            if(nextVal == spaceVal || nextVal == commaVal ){
                cin>>lineInput;
            }
        }
    } else {
        while (cin >> n) {
            t=isPrime(n);
            string tString;
            tString = t ? "true" : "false";
            cout<<n<<", "<<tString<<endl;
            nextVal = cin.peek();
            if(nextVal == spaceVal || nextVal == commaVal ){
                cin>>lineInput;
            }
        }
    }    
    return retVal;
};