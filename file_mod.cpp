#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  fstream myfile;
  int counter =0;
  int linesToAdd=3;
  string line;
  string fileName = "example.txt";

  myfile.open (fileName);
  cout << "From file:" <<endl;
  while (getline(myfile, line)){
    cout << line << "\n";
    counter++;
  }
  myfile.close();


  myfile.open (fileName, ios::app);
  for(int i=0; i<linesToAdd; i++){
    myfile << "This is line number " << counter+i+1 << endl;
  }
  myfile.close();
  
  return 0;
}

