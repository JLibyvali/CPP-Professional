//
// Created by jlibyvali on 24-3-31.
//


#include <iostream>
#include <fstream>
#include <string>
#include <string_view>


using namespace std;

int main() {


    cout<<"#########################Stream link##########################"<<endl;
    /*Any inStream and outStream can all build linker, so that can achieve flush-on-access
     * */

    ifstream inFile{"input.txt"};
    ofstream outFile{"output.txt"};

    inFile.tie(&outFile);   // pass the 'nullptr' to delete the link.

    outFile << "Hello this is ofstream data ";  // ofstream has not been flushed
    // but call infstream will trigger flush()

    string token;
    inFile >> token;    // token will read data from file , and write into stream
    cout<<token<<endl;

    cout<<"###########################bidirectional stream#########################"<<endl;

    return 0;
}