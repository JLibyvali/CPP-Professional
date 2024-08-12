#include "Tree.h"
#include <cstdio>
#include <ctime>
#include <cwchar>
#include <functional>
#include <memory>
#include <stack>
#include <stdexcept>
#include <vector>

int tre::Tree::TreeDepth() {
    return depth;
}

bool tre::Tree::isTreeEmpty() {
    return (HEAD == nullptr);
}

/**
 * @brief return root node
 *
 * @return tre::tnode&
 */
tre::tnode &tre::Tree::Root() {
    return *HEAD;
}

/**
 * @brief return one child's parent node
 *
 * @param child
 * @return tre::tnode&
 */
tre::tnode &tre::Tree::Parent(tnode &child) {

    if (HEAD->lchild == nullptr && HEAD->rchild == nullptr)
        return *HEAD;

    auto traverse = [&]() -> tnode & {
        auto cur = HEAD;

        std::stack<std::shared_ptr<tnode>> st;
        st.push(cur);

        while (!st.empty()) {
            auto tmp = st.top();

            if (*tmp == child)
                return *tmp;

            st.pop();

            if (tmp->rchild != nullptr) st.push(tmp->rchild);
            if (tmp->lchild != nullptr) st.push(tmp->lchild);
        }

        throw std::invalid_argument("Invalid child node\n");
    };

    auto res = traverse();
    return res;
}

tre::tnode &tre::Tree::Lchild(tre::tnode &src) {
    if (HEAD->lchild == nullptr && HEAD->rchild == nullptr)
        return *HEAD;

    // use stack to emulate recursion, mid-order traverse
    auto traverse = [&]() -> tnode & {
        auto cur = HEAD;
        std::stack<std::shared_ptr<tnode>> st;

        while (cur != nullptr || !st.empty()) {

            while (cur != nullptr) {
                st.push(cur);
                cur = cur->lchild;
            }

            auto tmp = st.top();
            st.pop();

            if (*tmp == src)
                return *tmp;

            cur = tmp->rchild;
        }
        throw std::invalid_argument("invalid src node");
    };

    auto res = traverse();
    return res;
}

tre::tnode &tre::Tree::Rchild(tre::tnode &src) {

    if (HEAD->lchild == nullptr && HEAD->rchild == nullptr)
        return *HEAD;

    // use stack to emulate recursion, post-order traverse
    auto traverse = [&]() -> tnode & {
        auto cur = HEAD;
        std::stack<std::shared_ptr<tnode>> st;

        st.push(cur);

        while (!st.empty()) {

            auto tmp = st.top();
            st.pop();

            if (*tmp == src)
                return *tmp;

            if (tmp->lchild) st.push(tmp->lchild);
            if (tmp->rchild) st.push(tmp->rchild);
        }
    };

    auto res = traverse();
    return res;
}

/**
 * @brief Traverse the tree by preorder
 *
 * @param next
 */
void tre::Tree::PreOrderTra(tre::tnode &next) {

    if (next.lchild == nullptr && next.rchild == nullptr) {
        printf("Leaf node: %d \n", next.id);
        return;
    }

    printf("tnode: %d \n", next.id);
    PreOrderTra(*next.lchild);
    PostOrderTra(*next.rchild);
}

/**
 * @brief Traverse the tree by midorder
 *
 * @param next
 */
void tre::Tree::MidOrderTra(tre::tnode &next) {

    if (next.lchild == nullptr && next.rchild == nullptr) {
        printf("Leaf node: %d\t", next.id);
        return;
    }

    if (next == *HEAD) {
        printf("| Root: %d | \t", next.id);
    }

    MidOrderTra(*next.lchild);
    printf("tnode: %d \t", next.id);
    MidOrderTra(*next.rchild);
}

/**
 * @brief Traverse the tree using Midorder, search Src node . Storage the right node into res
 *
 * @param next
 * @param src
 * @param res
 * @return bool If exist the src node and That node isn't full
 */
bool tre::Tree::MidOrderTra(tnode &next, tnode &src, tnode &res) {

    if (next.lchild == nullptr && next.rchild == nullptr) {

        if (next == src) {
            res = next;
            return true;
        }

        return false;
    }

    MidOrderTra(*next.lchild, src, res);

    if (next.id == src.id) {
        res = next;
        return true;
    }

    MidOrderTra(*next.rchild, src, res);
    return false;
}

/**
 * @brief Traverse the tree by postorder
 *
 * @param next
 */
void tre::Tree::PostOrderTra(tnode &next) {

    if (next.lchild == nullptr && next.rchild == nullptr) {
        printf("Leaf node: %d\t", next.id);
        return;
    }

    if (next == *HEAD) {
        printf("| Root: %d | \t", next.id);
    }

    PostOrderTra(*next.lchild);
    PostOrderTra(*next.rchild);

    printf("tnode: %d \t", next.id);
}

/**
 * @brief Insert node Src after node Dst, using DestTree, flag for lchild, or rchild
 *
 * @param destTree
 * @param dst
 * @param src
 * @param flag true for lchild, and false for rchild
 * @return int
 */
int tre::Tree::InsertNode(int _id, tnode &src, bool flag) {
    if (HEAD == nullptr)
        return -1;

    auto funct = [&]() -> tnode & {
        auto cur = HEAD;
        std::stack<std::shared_ptr<tnode>> st;

        st.push(cur);
        while (!st.empty()) {

            auto tmp = st.top();
            st.pop();

            if (tmp->id == _id)
                return *tmp;

            if (tmp->rchild) st.push(tmp->rchild);
            if (tmp->lchild) st.push(tmp->lchild);
        }
        throw std::invalid_argument("Invalid _id\n");
    };

    auto res  = funct();
    auto temp = std::make_shared<tnode>(new tnode());

    if (flag) {
        *temp      = src;
        res.lchild = std::make_shared<tnode>(&temp);

    } else {
        *temp      = src;
        res.rchild = std::make_shared<tnode>(&temp);
    }

    return 0;
}

int tre::Tree::Changenode(const Tree &te, int _old, int _new) {

    if (te.HEAD == nullptr)
        return -1;

    auto cur = HEAD;
    std::stack<std::shared_ptr<tnode>> st;

    auto traverse = [&, _old]() -> tnode & {
        st.push(cur);
        while (!st.empty()) {
            auto tmp = st.top();

            st.pop();

            if (tmp->id == _old)
                return *tmp;

            if (tmp->rchild) st.push(tmp->rchild);
            if (tmp->lchild) st.push(tmp->lchild);
        }

        throw std::invalid_argument("Invalid id\n");
    };

    auto res = traverse();
    res.id   = _new;

    return 0;
}

/**
 * @brief Destroy tree memory space
 *
 * @return int
 */
int tre::Tree::Destroy() {

    if (HEAD == nullptr)
        return -1;

    auto traverse = []() {
        auto cur = HEAD;
        std::stack<std::shared_ptr<tnode>> st;
        std::vector<std::shared_ptr<tnode> > res;

        st.push(cur);
        while (!st.empty()) {

            auto tmp = st.top();
            st.pop();

            res.push_back(tmp);

            if(tmp->lchild) st.push(tmp->lchild);
            if(tmp->rchild) st.push(tmp->rchild);
        }
    };
}

/**
 * @brief Set all elements to zero
 *
 * @return int
 */
int tre::Tree::Clear() {

    if (HEAD == nullptr)
        return 0;

    std::function<void(tre::tnode & next)> func = [&](tre::tnode &next) -> void {
        if (next.lchild == nullptr && next.rchild == nullptr) {
            next.id = 0;
            return;
        }

        func(*next.lchild);
        next.id = 0;
        func(*next.rchild);
    };

    return 0;
}
