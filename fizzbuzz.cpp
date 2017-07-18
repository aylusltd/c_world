#include <iostream>
#include <string>
using namespace std;

struct fizziebuzzie{
    int val;
    string display;
};

fizziebuzzie *makeFizzBuzzes(int n){
    fizziebuzzie *FizzieBuzzes = new fizziebuzzie[n];
    fizziebuzzie current;
    for(int i=1; i<=n; i++){
        current.val=i;
        current.display="";
        if(i%3 == 0){
            current.display+="Fizz";
        }
        if(i%5 == 0){
            current.display+="Buzz";
        }
        if(current.display == ""){
            current.display=to_string(i);
        }
        FizzieBuzzes[i-1]=current;
    }
    return FizzieBuzzes;
}

void logBuzzes(fizziebuzzie *FizzieBuzzes, int length){
    for(int i=0; i<length; i++){
        cout<<FizzieBuzzes[i].display;
        if(i<length-1){
            cout<<", ";
        } else {
            cout<<endl;
        }
    }
}

int main(){
    int fb;
    cout<<"How many FizzieBuzzes?"<<endl;
    cin>>fb;
    fizziebuzzie *FizzieBuzzes = new fizziebuzzie[fb];
    FizzieBuzzes = makeFizzBuzzes(fb);
    logBuzzes(FizzieBuzzes, fb);
    return 0;
}