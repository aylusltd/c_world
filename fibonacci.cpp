#include <iostream>
#include <string>
using namespace std;

void fibonacci(int n, int* fib){
    // static int seq[20];
    // cout << "n="<<n<<endl;
    int prev = 0;
    int current = 1;
    for(int i = 0; i < n; i++){
        fib[i] = current;
        current += prev;
        prev = fib[i];
    }
    // return seq;
}

int main(){
    
    int count;
    int length;

    cout << "How many numbers in the Fibonacci sequence should I show?";
    cout << endl;

    cin >> count;
    cout << endl << "Calculating now..." << endl;
    // Have to initialize here
    int fib[count];

    fibonacci(count, fib);
    length = sizeof(fib)/sizeof(*fib);
    bool overflowed = false;
    for(int i=0; i<length; i++){
        if(fib[i] > 0 && !overflowed){
            cout << fib[i];    
        } else {
            overflowed = true;
            cout<<"Integer Overflow";
        }
        
        if(i<length-1){
            cout<<", ";
        } else {
            cout<<endl;
        }    
    }

    cout<<endl;
    return 0;
}

