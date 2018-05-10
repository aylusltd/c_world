#include <iostream>
#include <assert.h>
#include <string>

#include "functor.hpp"
#include "stack.hpp"

// using namespace heap;
using namespace std;

void hello(){
    cout<<"Hello"<<endl;
}

void goodbye(){
    cout<<"Goodbye!"<<endl;
}

int main(){
    stack::Stack<int> i;
    i.push(5);
    assert(i.peek()==5);
    assert(i.peek()==5);
    i.push(50);
    i.push(15);
    assert(i.pop()==15);
    assert(i.peek()==50);
    i.clear();
    i.push(1);
    assert(i.pop()==1);

    return 0;
}

