#include <iostream>
#include <assert.h>

#include "heap.hpp"

using namespace heap;
using namespace std;

struct f{
    friend bool operator< (const f& lhs, const f& rhs){ return lhs.priority < rhs.priority; }

    friend bool operator> (const f& lhs, const f& rhs){ return rhs < lhs; }
    friend bool operator<=(const f& lhs, const f& rhs){ return !(lhs > rhs); }
    friend bool operator>=(const f& lhs, const f& rhs){ return !(lhs < rhs); }

    unsigned int priority;
    void (*action)();
};

void hello(){
    cout<<"Hello"<<endl;
}

void goodbye(){
    cout<<"Goodbye!"<<endl;
}

int main(){
    Heap<int> i;
    i.add(5);
    assert(i.peek()==5);
    assert(i.peek()==5);
    i.add(50);
    i.add(15);
    assert(i.poll()==5);
    assert(i.peek()==15);

    Heap<char> j;
    j.add('a');
    assert(j.peek()=='a');
    assert(j.peek()=='a');
    j.add('q');
    j.add('l');
    assert(j.poll()=='a');
    assert(j.peek()=='l');

    Heap<f> k;
    f a;
    a.priority = 7;
    a.action=hello;
    f b;
    b.priority = 17;
    b.action=goodbye;
    f c;
    c.priority = 70;
    c.action=hello;

    k.add(a);
    assert(k.peek().priority == 7);
    assert(k.peek().priority == 7);
    k.add(c);
    k.add(b);
    f d = k.poll();
    d.action();
    assert(d.priority==7);
    d = k.peek();
    assert(d.priority==17);
    d.action();


    return 0;
}

