#include <iostream>
#include <assert.h>
#include <string>

#include "functor.hpp"
#include "heap.hpp"

// using namespace heap;
using namespace std;

void hello(){
    cout<<"Hello"<<endl;
}

void goodbye(){
    cout<<"Goodbye!"<<endl;
}

int main(){
    heap::Heap<int> i;
    i.add(5);
    assert(i.peek()==5);
    assert(i.peek()==5);
    i.add(50);
    i.add(15);
    assert(i.poll()==5);
    assert(i.peek()==15);

    heap::Heap<char> j;
    j.add('a');
    assert(j.peek()=='a');
    assert(j.peek()=='a');
    j.add('q');
    j.add('l');
    assert(j.poll()=='a');
    assert(j.peek()=='l');

    heap::Heap<f> k;
    f a;
    a.priority = 7;
    a.action=hello;
    f b;
    b.priority = 17;
    b.action=goodbye;
    f c;
    c.priority = 70;
    c.action=hello;

    f e;
    e.priority=8;
    e.action=goodbye;

    k.add(a);
    assert(k.peek().priority == 7);
    assert(k.peek().priority == 7);
    k.add(c);
    k.add(b);
    k.add(e);
    f d = k.poll();
    d.action();
    assert(d.priority==7);
    d = k.peek();
    assert(d.priority==8);
    d.action();


    return 0;
}

