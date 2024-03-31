//
// Created by jlibyvali on 24-3-31.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace  std;


int main(){
    cout << "############################FILE STREAM###########################" << endl;

    const char* argc {"This is test txt content"};
    ofstream outFile {"test.txt",ios_base::trunc};
    if(outFile.fail()){
        cerr<<"Error while openning files"<<endl;
        return -1;
    }
    outFile << argc <<endl;

    outFile = ofstream ("test.txt",ios_base::app);
    outFile.seekp(ios_base::beg);
    string str = "This will insert in Head";
    outFile << str <<endl;

    return 0;
}