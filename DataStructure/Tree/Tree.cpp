#include "Tree.h"
#include <cstdio>
#include <functional>
#include <stdexcept>

int tre::Tree::TreeDepth() { return depth; }

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
void tre::Tree::PostOrderTra(tre::tnode &next) {

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
 * @brief return root node
 *
 * @return tre::tnode&
 */
tre::tnode &tre::Tree::Root() {
    return *HEAD;
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
int tre::Tree::InsertNode(tre::tnode &dst, tre::tnode &src, bool flag) {
    if (HEAD == nullptr)
        return -1;

    if (flag) {

        std::function<void(tre::tnode & next)> funct = [&](tre::tnode &next) {
            if (next.lchild == nullptr && next.rchild == nullptr) {
                if (next.id == dst.id) {

                    next.lchild = &src;
                    return;

                } else {
                    return;
                }
            }

            funct(*next.lchild);

            if (next.id == dst.id) {

                next.lchild = &src;
                return;
            } else {
                return;
            }

            funct(*next.rchild);
        };

    } else {
        std::function<void(tre::tnode & next)> funct = [&](tre::tnode &next) {
            if (next.lchild == nullptr && next.rchild == nullptr) {
                if (next.id == dst.id) {

                    next.rchild = &src;
                    return;
                    
                } else {
                    return;
                }
            }

            funct(*next.lchild);

            if (next.id == dst.id)
                next.rchild = &src;

            funct(*next.rchild);
        };
    }

    return 0;
}

/**
 * @brief Insert one subtree at dst'
 *
 * @param destTree
 * @param dst
 * @param src
 * @param flag true for left child and false for  right child
 * @return int
 */
int tre::Tree::InsertTree(Tree &destTree, tnode &dst, Tree &src, bool flag) {
    if (HEAD == nullptr)
        return -1;

    if (flag) {

        std::function<void(tre::tnode & next, tre::tnode & res)> funct = [&](tre::tnode &next, tre::tnode &res) {
            if (next.lchild == nullptr && next.rchild == nullptr) {
                if (next.id == dst.id) {
                    next.lchild = HEAD;
                    return;
                } else {
                    return;
                }
            }

            funct(*next.lchild, res);

            if (next.id == dst.id) {
                next.lchild = HEAD;
                return;
            } else {
                return;
            }

            funct(*next.rchild, res);
        };

    } else {
        std::function<void(tre::tnode & next, tre::tnode & res)> funct = [&](tre::tnode &next, tre::tnode &res) {
            if (next.lchild == nullptr && next.rchild == nullptr) {
                if (next.id == dst.id) {
                    next.rchild = HEAD;
                    return;
                } else {
                    return;
                }
            }

            funct(*next.lchild, res);

            if (next.id == dst.id) {
                next.rchild = HEAD;
                return;
            } else {
                return;
            }

            funct(*next.rchild, res);
        };
    }
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

    std::function<void(tre::tnode & next)> func = [&](tre::tnode &next) -> void {
        if (next.lchild == nullptr && next.rchild == nullptr) {
            return;
        }

        func(*next.lchild);
        delete next.lchild;
        next.lchild = nullptr;
        func(*next.rchild);
        delete next.rchild;
        next.rchild = nullptr;
    };

    delete HEAD;
    HEAD = nullptr;
    return 0;
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
