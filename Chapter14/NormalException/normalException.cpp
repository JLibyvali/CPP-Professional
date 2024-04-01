//
// Created by jlibyvali on 24-4-1.
//

#include <iostream>
#include <stdexcept>
#include <limits>
#include <source_location>

using namespace std;


// new handler
class please_terminate_me : public bad_alloc {
};

void myNewhandler() {

    /*default not new-handler,
     * ***IMPORTANT*** handler should not return, when allocate fail will call handler, if return, the allocated-thread will keep allocating memory.so it lead to dead-loop.
     * In new handler:
     * 1.can storage exception memory information, catch the excepted parts.
     * 2. throw different type exception
     *
     * */

    cerr << "THIS is handler" << endl;
    throw please_terminate_me();    // called terminate will shut down program

}

// ctor error
template<typename T>
class Matrix {
public:

    Matrix(size_t width, size_t height) {
        // the first new throw exception is not a big deal, case there exist no memory to free.
        m_matrix = new T *[width]{};   // Use '{}' to initialize 0, not just allocate memory
        m_width = width;
        m_height = height;
        try {
            for (size_t i = 0; i < width; i++) {
                m_matrix[i] = new T[height];
            }
        } catch (...) {   // case don't know the exception type exactly.
            // it also avoids the exception leave the ctor, so that the dtor must be callded.
            cerr << "Allocate exception failed ,call cleanup()" << endl;
            cleanup();
            throw_with_nested(bad_alloc());
        }

    }

    virtual  ~Matrix() {
        cleanup();
    }

private:

    void cleanup() {
        for (size_t i = 0; i < m_width; ++i) {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
        m_matrix = nullptr;
        m_width = m_height = 0;
    }

    size_t m_width{0}, m_height{0};
    T **m_matrix{nullptr};

};

// test
class ele{
public:
    ele(){
        throw runtime_error(" Ctor throw exception");
    }
private:
    int m_value;
};

int main() {

    cout << "###################Memory Allocate Error#######################################" << endl;
    // when allocate huge memory-block , use the try-catch

//
//    cout << "Trying to allocate huge memory block " << endl;
//    try {
//        new_handler oldHandler{set_new_handler(myNewhandler)};  // set handler and save it into oldHandler.
//        size_t intSize{numeric_limits<size_t>::max()};
//        int *ptr = new int[intSize]; // When 'new; throw exception
//        set_new_handler(oldHandler);    // apply handler
//    } catch (const please_terminate_me &e) {
//
//        auto locat{source_location::current()};
//        cerr << locat.file_name() << ": " << locat.line() << " |" << "Unable to allocate memory: " << e.what() << endl;
//
//    }

    cout << "######################Ctor Error########################################################" << endl;
    Matrix<ele> ma {10,10};
    return 0;
}