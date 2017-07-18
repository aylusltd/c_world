#include <iostream>
#include <string>
// #include <vector>
// #include <sys/ioctl.h>
// #include <stdio.h>
// #include <unistd.h>
#include <fstream>
// #include <math.h>

using namespace std;

// class leaf{
//     public:
//         leaf(int val){
//             this->_value=val;
//         }
//         ~leaf(){};
//         int value(){
//             return this->_value;
//         } 
//     private:
//         int _value;
// };

// class node{
//     public:
//         node(){};
//         ~node(){};
//         int value(){
//             return this->_value;
//         }
//     private:
//         int _value;
// };

class bTree
{
    public:
        bTree(){

        };
        bTree(int val){
            if(val == 0){
                cerr<<"GOT INITIALIZED WITH A ZERO"<<endl;
            }
            this->value(val);
            this->_length=1;
            this->left=NULL;
            this->right=NULL;
            this->_length=1;
        };
        bTree(int val, bTree *left, bTree *right){
            this->value(val);
            this->left = left;
            this->right = right;
            if(left->length() > right->length()){
                this->_length = left->length();
            } else {
                this->_length = right->length();
            }
            _length++;
        };
        bTree(int val, bTree *left, bTree *right, bTree *parent){
            this->value(val);
            this->left = left;
            this->right = right;
            this->left = left;
            this->parent = parent;
        };
        ~bTree(){

        };

        int value(){
            return this->_value;
        };
        void value(int newVal){
            this->_value=newVal;
        };
        int length(){
            return this->_length;
        };
        bTree *left;
        bTree *right;
        bTree *parent;
        bool walked;

        bTree append(bTree child){
            if(this->left != NULL && this->left->value() == 0){
                cerr<<"got a zero value kid"<<endl;
            }
            if(this->value()==0){
                cerr<<"All out of love"<<endl;
            }
            cout<<"PARENT:"<<endl;
            cout<<this->toString()<<endl;
            cout<<"Child: "<<endl;
            cout<<child.toString()<<endl;
            
            if(this->left != NULL && child.value() <= this->value()){
                cout<<"passed left"<<endl<<endl;
                return this->left->append(child);
            } else if(this->right != NULL && child.value() > this->value()){
                cout<<"passed right"<<endl<<endl;
                return this->right->append(child);
            } else if(this->left == NULL && child.value() <= this->value()){
                cout<<"added left"<<endl;
                this->left = &child;
                child.parent = this;
            } else if(this->right==NULL && child.value() > this->value()){
                cout<<"added right"<<endl;
                this->right = &child;
                child.parent = this;
            }
            this->_length++;
            return *this;
        };
        string toString(){
            string str="";
            str+="\nPRETTY PRINT\n";
            str+="value: "+to_string(this->value())+"\n";
            if(this->left && this->left->value()){
                str+="left: "+to_string(this->left->value())+"\n";    
            } else {
                str+="left: undefined\n";
            }
            if(this->right && this->right->value()){
                str+="right: "+to_string(this->right->value())+"\n";
            } else {
                str+="right: undefined\n";
            }
            str+="length: "+to_string(this->_length)+"\n";

            return str;
        }

    int _value;
    int _length;

};

void walk(bTree *tree, int indent, int line, bTree *prev){
    string filename = "ouput.txt";
    bTree myTree = *tree;
    
    if(myTree.left != NULL && myTree.left->walked == false){
        myTree.left->walked=true;
        return walk(myTree.left, indent + 4, line+1, tree);
    } else if(myTree.right != NULL && myTree.right->walked == false){
        myTree.right->walked=true;
        return walk(myTree.right, indent + 4, line+1, tree);
    } else if(prev != NULL){
        return walk(prev, indent - 4, line-1, NULL);
    } else {
        return;
    }
}

struct console{
    void log(string str){
        cout<<str<<endl;
    };
    void err(string str){
        cerr<<str<<endl;
    }
};

int main(){
    console c;
    // bTree node1(1);
    // bTree node2(2);
    bTree arr[20];
    cout<<"INITIALIZING"<<endl;
    for(int i=0; i<10; i++){
        arr[i] = bTree(i+1);
        arr[i+1] = bTree(rand() % 100 + 1);
    }
    // c.log(node1.toString());
    // c.log(node2.toString());
    // bTree node3(3);
    cout<<"APPENDING"<<endl;

    for(int i=1; i<20; i++){
        arr[0].append(arr[i]);
    }

    // node2.append(node1);
    // node2.append(&node3);
    // c.log(node2.toString());
    return 0;
}