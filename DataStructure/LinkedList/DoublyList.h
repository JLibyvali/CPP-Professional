// List node
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

struct node {
    int id;
    node *prev;
    node *next;
    node() {
        id   = 0;
        prev = nullptr;
        next = nullptr;
    }

    node(int _id) : id(_id) {
        prev = next = nullptr;
    }
};

// List status
enum class STATUS {
    LIST_OK,
    LIST_EXCEPTION,
    LIST_MEMEXCEPT,
};

// List
/**
 * @brief Remember the static data-mambers usage,
    use ' ClassName::static-member;
 * 
 */
class DoubleList {

  public:
    DoubleList() : DoubleList(0) {} // using other ctor to initialize one list.

    DoubleList(int _id) {
        node *tmp        = new node(_id);
        DoubleList::HEAD = tmp;
        DoubleList::END  = tmp;
    }

    STATUS createList(int _id);
    STATUS clearList();
    STATUS insert(int pos);
    STATUS insert(int _id, int pos);
    node &del_ele(int _id );
    STATUS print();
    STATUS reverse();
    node &get_node(int _id);
    STATUS change_node(int _id, int _new);

  private:
    node *HEAD = nullptr;
    node *END  = nullptr;
    int getLen() {
        node *cur = HEAD;
        int len   = 0;

        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        return len;
    }
};

#endif