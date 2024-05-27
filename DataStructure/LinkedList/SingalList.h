#ifndef SINGALLIST_H
#define SINGALLIST_H

struct node {
    double id;
    node *next;

    node() {
        id   = 0;
        next = nullptr;
    }

    node(double _id) {
        id   = _id;
        next = nullptr;
    }
};

class SList {

  public:
    SList() : SList(0.0) {}
    SList(double _id);

    bool insert(int pos, double _id = 0.0);

    node &del(double _id);
    node &get_node(double _id);
    node &chang_node(double _id, double _new);
    void reverse();
    void print();

    void clear();

  private:
    inline static node *HEAD = nullptr;
    inline static node *END  = nullptr;

    int getLen() {
        int len = 1;

        node *cur = HEAD;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }

        return len;
    }
};

#endif