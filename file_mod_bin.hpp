#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef int8_t  BYTE;
namespace f{
  vector<BYTE> makeBytes(string input){
      char holder;
      BYTE num;
      stringstream ss(input);
      vector<BYTE> dataValues;
      ss>>noskipws;
      while(ss >> std::hex >> num || !ss.eof()){
          if(ss.fail()) {
              ss.clear();
              ss >> holder; 
              continue;
          }
          if(num) {
              dataValues.push_back(static_cast<BYTE>(num));
          }
          else {
              // cout<<"Bad num: ";
              // cout<<num;
              // cout<<endl;
          }
      }
      return dataValues;
  }

  void save(vector<BYTE> output, string filename){
      fstream myfile;
      myfile.open(filename, ios::out | fstream::binary);
      for(unsigned long int i=0; i<output.size(); i++){
          myfile<<output[i];
      }
      myfile.close();
  }

  vector<BYTE> readFile(string fileName){
    fstream myfile;
    vector<BYTE> output;
    BYTE in;
    string data;
    string chunk;
    myfile.open(fileName, fstream::binary | ios::in);
    myfile>>noskipws;
    while(myfile>>in){
      // in-=200;
      output.push_back(in);
      // cout<<in;
    }
    // cout<<endl;
    myfile.close();
    return output;
  }
}
// int main () {
//   fstream myfile;
//   string line;
//   string fileName = "example2.txt";

//   string test = "this is a test";
//   vector<BYTE> v = makeBytes(test);
//   save(v,fileName);
//   vector<BYTE> output=readFile(fileName);
//   unsigned long int i;
//   unsigned long int j=output.size();
//   for(i=0; i<j; i++){
//     cout<<output[i];  
//   }
//   cout<<endl;

  
  
//   return 0;
// }

