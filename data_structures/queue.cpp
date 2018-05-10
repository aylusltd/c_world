#include <iostream>
#include <assert.h>
#include <string>

#include "functor.hpp"
#include "queue.hpp"

// using namespace heap;
using namespace std;

void hello(){
    cout<<"Hello"<<endl;
}

void goodbye(){
    cout<<"Goodbye!"<<endl;
}

int main(){
    queue::Queue<int> i;
    i.push(1);
    i.push(2);
    i.push(3);
    i.push(4);
    i.push(5);
    i.push(6);

    assert(i.peek()==1);
    assert(i.peek()==1);
    i.push(7);
    i.push(8);
    assert(i.pop()==1);
    assert(i.pop()==2);
    assert(i.pop()==3);

    assert(i.peek()==4);
    i.clear();
    i.push(1);
    assert(i.pop()==1);

    return 0;
}

