#include "SingalList.h"
#include <ios>
#include <istream>
#include <stdexcept>
#include <cstdio>

/**
 * @brief Construct a new SList::SList object, with given id
 *
 * @param _id
 */
SList::SList(double _id) {

    node *tmp = new node(_id);

    SList::HEAD = tmp;
    SList::END  = tmp;
}

void SList::print() {

    std::iostream::sync_with_stdio(false);

    if (SList::HEAD == nullptr || SList::END == nullptr)
        return;

    node *cur = SList::HEAD;

    printf("======================\n");
    while (cur != nullptr) {
        printf("| %.6f |\n", cur->id);
        cur = cur->next;
    }
    printf("==========================\n");
}

/**
 * @brief insert node with given id ? Maybe can be more simple
 *
 * @param pos
 * @param _id
 * @return true
 * @return false
 */
bool SList::insert(int pos, double _id) {

    if (SList::HEAD == nullptr || SList::SList::END == nullptr)
        return false;

    node *tmp = new node(_id);

    if (pos == 0) {
        SList::END->next = tmp;
        SList::END       = tmp;
        return true;
    } else if (pos == 1) {
        tmp->next   = SList::HEAD;
        SList::HEAD = tmp;
        return true;
    } else {
        if (pos < getLen()) {

            node *cur  = SList::HEAD;
            node *prev = SList::HEAD;
            int n      = 1;
            for (cur, n; cur != nullptr; n++, cur = cur->next) {

                if (n == pos) {
                    prev->next = tmp;
                    tmp->next  = cur;
                }
                prev = cur;
            }
            return true;

        } else {
            throw std::runtime_error("Pos is bigger than length");
        }
    }
}

/**
 * @brief using 'prev' and 'cur' to delete node
 *
 * @param _id
 * @return node& , return the res node
 */
node &SList::del(double _id) {

    if (SList::HEAD == nullptr || SList::END == nullptr)
        throw std::runtime_error("List is empty");

    node *res  = new node();
    node *cur  = SList::HEAD;
    node *prev = SList::HEAD;
    for (cur; cur != nullptr; cur = cur->next) {

        if (cur->id == _id) {

            prev->next = cur->next;
            res        = cur;

            return *res;
        }

        prev = cur;
    }

    throw std::runtime_error("Exception occurred When del node");
}

node &SList::get_node(double _id) {

    if (SList::HEAD == nullptr || SList::END == nullptr)
        throw std::runtime_error("List is empty");

    node *cur = SList::HEAD;
    while (cur != nullptr) {
        if (cur->id == _id) {
            return *cur;
        }

        cur = cur->next;
    }

    throw std::runtime_error("Exception occurred when get node");
}

/**
 * @brief traverse all node and find the right node
 *
 * @param _id
 * @param _new
 * @return node&
 */
node &SList::chang_node(double _id, double _new) {

    if (SList::HEAD == nullptr || SList::END == nullptr)
        throw std::runtime_error("List is empty");

    node *cur = SList::HEAD;

    while (cur != nullptr) {

        if (cur->id == _id) {

            cur->id = _new;
            return *cur;
        }
    }

    throw std::runtime_error("Exception occurred when chang node id");
}

/**
 * @brief Using three pointer to reverse list
 *
 */
void SList::reverse() {

    if (SList::HEAD == nullptr || SList::END == nullptr)
        return;

    node *prev  = nullptr;
    node *cur   = SList::HEAD;
    node *_next = cur->next;

    for (_next, cur; cur != nullptr;( _next = (_next == nullptr) ? nullptr : _next->next ) ) {
        cur->next = prev; // reverse current node link
        prev      = cur;  // move the prev node pointer

        cur = _next; // move cur pointer to next node
    }

    node *tmp;
    tmp         = SList::HEAD;
    SList::HEAD = SList::END;
    SList::END  = tmp;
    return;
}

/**
 * @brief set node's pointer to nullptr
 *
 */
void SList::clear() {

    if (SList::HEAD == nullptr || SList::END == nullptr)
        return;

    node *tmp;
    node *cur = SList::HEAD;

    while (cur != nullptr) {

        tmp       = cur->next;
        cur->next = nullptr;
        cur       = nullptr;

        cur = tmp;
    }

    SList::HEAD  = SList::END = nullptr;
    return;
}