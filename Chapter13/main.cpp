#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


int main() {

    cout << "###########################IO-Stream###################" << endl;
    // cin or cout
    // put or write.
    const char *tmp{"hello,world\n"};
    cout.write(tmp, strlen(tmp));
    cout.put('A');

    // cout.flush : refresh buffer
    /* refresh the buffer usually to improve the performance
     * */
    cout << "abc";
    cout.flush();
    cout << "defg\n";

    // stream error: stream has: good(),bad(),fail(). and Stream contains override of 'bool'
    cout.flush();
    if (cout.fail()) {
        cout << "Stream refresh failed " << endl;
    }
    if (cout) {
        cout << "Stream is normal" << endl;
    }

    // specially, when meet 'EOF': good == (!fail() && !eof() )

    cout << "##################Output manipulator########################" << endl;

    bool bool1{true};
    cout << "Default: " << bool1 << " Manipulator: " << boolalpha << bool1
         << endl; // Manipulator will only affect variable behind it.
    cout << "The setw(): " << setw(6) << 123 << endl;
    cout << "The setfill(): " << setfill('-') << setw(8) << 67 << endl;

    int num = 0, sum = 0;

    if (!cin.good()) {
        cerr << "Standard input is in  bade state" << endl;
        return -1;
    }

    while (!cin.bad()) {

        cin >> num;
        if (cin.good()) {
            sum += num;
        } else if (cin.eof()) {
            break;  // reached end of file
        } else {
            cin.clear();
            string badToken;
            cin >> badToken;  // When stream error, will call this cin.
            cerr << "WARNING: BAD INPUT: " << badToken << endl;
        }

    }

    cout << "Result: " << sum << endl;

    cout << "########################STRING STREAM###########################" << endl;
    /*there are ostringstream and istringstream, the ostringstream can read data from stream and write in sting,
     * the istringstream can read data from string , and write in stream.
     *
     * */

    ostringstream outstr1;

    while (cin) { // if get 'eof' or other will be false

        string token;
        cout << "Input next token :";
        cin >> token;

        if (!cin || token == "done ") {
            break;
        }

        outstr1 << token << " \t "; // out token into ostringstream
    }

    cout << "The result: " << outstr1.str() << endl;      // stringstream use 'str()' to  string object

    cout << "####INPUT STREAM" << endl;
    istringstream inStr1;

    struct Muffin {
        int m_size;
        string m_des;
        bool m_hasChips;
    };
    string des;
    bool hasChips;
    int size;


    /*It's an important application that using the 'stringstream' get all data at once,
     * and divide the data into different parts, which also called marshall.
     *
     * */

    inStr1 >> des >> size >> boolalpha >> hasChips;

    if (inStr1) {
        Muffin muffin1;
        muffin1.m_des = des;
        muffin1.m_size = size;
        muffin1.m_hasChips = hasChips;
    }

    return 0;
}
