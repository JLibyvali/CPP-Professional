#ifndef __QUEUE_H
#define __QUEUE_H

#include <string>
#include <variant>
namespace que {

const static int MAX_LEN = 100;
struct qnode {

    int id;
    char c;
    std::variant<float, std::string> specs;

    qnode(int _id = 0, char _c = 'Z', std::variant<float, std::string> _specs = "Default node") {
        id    = _id;
        c     = _c;
        specs = _specs;
    }
};

class Queue_circle {
};

class Queue_list {
};

}

#endif