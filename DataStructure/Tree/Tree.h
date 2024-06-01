#ifndef __TREE_H
#define __TREE_H

#include <compare>

namespace tre {

/**
 * @brief We can describe a tree use: Parent describe, Degree describe, and Child describe .
    For better traversing tree and cost fewer memory. Better use Child describe method.
 * @note This struct type used fot binary Tree.
 *
 */
struct tnode {

    int id;

    tnode *lchild;
    tnode *rchild;

    tnode() {
        id     = 0;
        lchild = rchild = nullptr;
    }
    tnode(int _id) {
        id     = _id;
        lchild = rchild = nullptr;
    }
    ~tnode() {
        delete lchild;
        delete rchild;
        lchild = rchild = nullptr;
    }

    // operator
    auto operator<=>(const tre::tnode &src) const noexcept = default;
};

class Tree {

  public:
    Tree() {
        HEAD            = new tre::tnode();
        depth           = 1;
    }

    void CreateTree(tre::tnode &root, int n);
    int Destroy();
    int Clear();

    bool isTreeEmpty();
    int TreeDepth();

    tnode &Root();

    int Changenode(const Tree &te, const tnode &dst, int _id);

    tnode &Parent(tnode &_child);
    tnode &Lchild(tnode &src);
    tnode &Rchild(tnode &src);

    int InsertTree(Tree &destTree, tnode &dst, Tree &src, bool flag);
    int InsertNode(tre::tnode &dst, tre::tnode &src, bool flag);
    int DelTree(Tree &src, tnode &dst, int n);

    // Traverse
    void PreOrderTra(tnode &next);
    void MidOrderTra(tnode &next);
    void PostOrderTra(tnode &next);

    // Traverse for search
    bool MidOrderTra(tnode &next, tnode &src, tnode &res);

  private:
    tnode *HEAD;
    int depth = 0;
};

}

#endif