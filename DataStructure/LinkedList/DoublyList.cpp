#include "DoublyList.h"
#include <cstdio>
#include <istream>
#include <stdexcept>

using namespace std;

/**
 * @brief create one list with node given _id
 *
 * @param _id
 * @return STATUS
 */
STATUS DoubleList::createList(int _id) {
    HEAD = END = nullptr;
    node *tmp  = new node(_id);
    HEAD       = tmp;
    END        = tmp;

    if (HEAD != nullptr && END != nullptr)
        return STATUS::LIST_OK;
    else
        return STATUS::LIST_EXCEPTION;
}

/**
 * @brief clear list and free memory
 *
 * @return STATUS
 */
STATUS DoubleList::clearList() {

    if (HEAD == nullptr || END == nullptr) {
        return STATUS::LIST_EXCEPTION;
    }

    node *cur = HEAD;
    node *tmp;
    // traverse all node to delete the list
    while (cur != nullptr) {
        tmp = cur;
        cur = cur->next;

        tmp->next = tmp->prev = nullptr;
        delete tmp;
        tmp = nullptr;
    }

    HEAD = END = nullptr;
    return STATUS::LIST_OK;
}

/**
 * @brief insert node at position, pos: '0' for end, '1' for start , and other should be "pos > 1".
 *
 * @param pos
 * @return STATUS
 */
STATUS DoubleList::insert(int pos) {

    if (HEAD == nullptr || END == nullptr)
        return STATUS::LIST_EXCEPTION;

    node *tmp = new node();

    if (pos == 1) {
        tmp->next  = HEAD; // build link between node and first node
        HEAD->prev = tmp;

        HEAD = tmp;
    } else if (pos == 0) {
        tmp->prev = END;
        END->next = tmp;

        END = tmp;
    } else {

        if (pos > DoubleList::getLen() - 1) {
            return STATUS::LIST_EXCEPTION;
        } else {

            node *cur = HEAD;
            int len   = 1;
            for (cur, len; cur != nullptr; cur = cur->next, ++len) {
                if (len == pos) {
                    tmp->prev       = cur->prev; // build 'prev' link between new node and prev node
                    cur->prev->next = tmp;

                    tmp->next = cur;
                    cur->prev = tmp;
                }
            }
        }
    }

    return STATUS::LIST_OK;
}

/**
 * @brief insert node at 'pos' with specific node-id
 *
 * @param id
 * @param pos
 * @return STATUS
 */
STATUS DoubleList::insert(int id, int pos) {

    if (HEAD == nullptr || END == nullptr)
        return STATUS::LIST_EXCEPTION;

    node *tmp = new node(id);

    if (pos == 1) {
        tmp->next  = HEAD; // build link between node and first node
        HEAD->prev = tmp;

        HEAD = tmp;
    } else if (pos == 0) {
        tmp->prev = END;
        END->next = tmp;

        END = tmp;
    } else {

        if (pos > DoubleList::getLen() - 1) {
            return STATUS::LIST_EXCEPTION;
        } else {

            node *cur = HEAD;
            int len   = 1;
            for (cur, len; cur != nullptr; cur = cur->next, ++len) {
                if (len == pos) {
                    tmp->prev       = cur->prev; // build 'prev' link between new node and prev node
                    cur->prev->next = tmp;

                    tmp->next = cur;
                    cur->prev = tmp;
                }
            }
        }
    }

    return STATUS::LIST_OK;
}

/**
 * @brief delete one node with given _id
 *
 * @param _id
 * @return node&
 */
node &DoubleList::del_ele(int _id) {

    if (HEAD == nullptr || END == nullptr)
        throw runtime_error("LIST EMPTY");

    node *cur = HEAD;
    while (cur != nullptr) {

        if (cur->id == _id) {
            node *res = cur;

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            return *res;    // return local variable, don't need free memory handly
        }

        cur = cur->next;
    }

    throw runtime_error("Delete failed");
}

STATUS DoubleList::print() {
    iostream::sync_with_stdio(false);
    if (HEAD == nullptr || END == nullptr)
        return STATUS::LIST_EXCEPTION;

    node *cur = HEAD;

    printf("NULL---\n");
    while (cur != nullptr) {
        printf("|p:%p | %d |n:%p |->\n", cur->prev, cur->id, cur->next);
        cur = cur->next;
    }
    return STATUS::LIST_OK;
}

/**
 * @brief traverse the List and change the 'prev' and 'next'
 *
 * @return STATUS
 */
STATUS DoubleList::reverse() {
    node *tmp = nullptr;

    // First update HEAD and END
    tmp  = HEAD;
    HEAD = END;
    END  = tmp;

    node *cur = HEAD;
    while (cur != nullptr) {

        tmp       = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;

        cur = cur->next;
    }

    return STATUS::LIST_OK; // If func no return value, may call system exception
}

/**
 * @brief search one node and return it
 *
 * @param _id
 * @return node&
 */
node &DoubleList::get_node(int _id) {

    if (HEAD == nullptr || END == nullptr)
        throw runtime_error("LIST is EMPTY");

    node *cur = HEAD;
    node *ref = nullptr;

    while (cur != nullptr) {

        if (cur->id == _id) {
            return *cur;
        }

        cur = cur->next;    // remember move cur
    }

    throw runtime_error("NODE can't found");
}

/**
 * @brief change one node id
 *
 * @param _id
 * @param _new
 * @return STATUS
 */
STATUS DoubleList::change_node(int _id, int _new) {

    if (HEAD == nullptr || END == nullptr)
        throw runtime_error("LIST is EMPTY");

    node *cur = HEAD;

    bool f = false;
    while (cur != nullptr) {
        if (cur->id == _id) {
            cur->id = _new;
            f       = true;
        }
        cur = cur->next;
    }

    if (f)
        return STATUS::LIST_OK;
    else
        return STATUS::LIST_EXCEPTION;
}