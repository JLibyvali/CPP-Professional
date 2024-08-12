#ifndef __TREE_H
#define __TREE_H

#include <compare>
#include <concepts>
#include <cstddef>
#include <memory>
#include <utility>

namespace tre {

/**
 * @brief We can describe a tree use: Parent describe, Degree describe, and Child describe .
    For better traversing tree and cost fewer memory. Better use Child describe method.
 * @note This struct type used fot binary Tree.
 *
 */
struct tnode {

    int id;

    std::shared_ptr<tnode> lchild = std::make_shared<tnode>();
    std::shared_ptr<tnode> rchild = std::make_shared<tnode>();

    /**
     * @brief swap data-member, been used for 'copy-assignment' and 'movement'. It's convenient for update
     *
     * @param src
     */
    // void swap(tre::tnode &src) {
        // std::swap(id, src.id);
        // std::swap(lchild, src.lchild);
        // std::swap(rchild, src.rchild);
    // }
// 
    // /**
    //  * @brief swap for right-reference, Making sure that never using 'src' after movement
    //  * 
    //  * @param src 
    //  */
    // void swap(tre::tnode &&src)  noexcept {
        // id = std::exchange(src.id, 0);
        // lchild = std::exchange(src.lchild, nullptr);
        // rchild = std::exchange(src.rchild, nullptr);
// 
    // }

    // IF you had to overwrite the 'func(T& src)' and 'func(T&& src)'
    // YOU can write 'func(T src){  this = std::move(src);  } : Using the value-passion to those parameter must been copy
    void swap(tre::tnode src){
      *this = std::move(src);
    }
    // IF src is Left-value, it will copy once, IF src is right-value, it will not copy.


    tnode() : id(0), lchild(nullptr), rchild(nullptr) {}
    tnode(int _id) : id(_id), lchild(nullptr), rchild(nullptr) {}
    ~tnode() = default;

    // Copy
    tnode(const tnode &lhs) : id(lhs.id), lchild(lhs.lchild), rchild(lhs.rchild) {
    }

    // Copy-assignment , using the 'copy and swap' to avoid bad alloc by exception.
    // Also should know the 'Shallow-copy' and "Depp-copy"
    tnode &operator=(tnode &lhs) {
        if (this == &lhs)
            return *this;

        swap(lhs);
        return *this;
    }

    // Move: should never throw exception
    tnode(tnode & src) noexcept {
      swap(src);
    }

    tnode &operator=(tnode &&src) noexcept {
      swap(src);
      return *this;
    }

    // After define 'operator <=>', compiler will auto generate: <, >, <=, >=
    // After define 'operator ==', compiler will auto generate: ==, !=
    auto operator<=>(const tre::tnode &src) const noexcept = default;
    auto operator==(const tre::tnode &src) const noexcept {
        return (this->id == src.id);
    }
};
// After knowing the movement, you can use 'movement' to implement normal swap():
//  Traditionally:
//         template<typename  T>
//         void swap(T& a, T& b){
//           T tmp {a};  IF 'tmp' is LARGE object, it will cost a lot.
//           a = b;
//           b = tmp;
//         }
//  Now:
//        template<typename  T>
//        void swap(T& a, T& b){
//         
//         T tmp   {std::move(a)};
//         a = std::move(b);
//         b = std::move(a);
//         
//       }
// 
// 

void swap(tre::tnode &first, tre::tnode &second) {
    first.swap(second);
}

class Tree {

  public:
    Tree();

    /**
     * @brief Create a Tree object, Full binary tree, with depth;
     *
     * @param root
     * @param depth
     */
    void CreateTree(tre::tnode &root, int depth);

    /**
     * @brief Destroy tree, free memory
     *
     * @return int
     */
    int Destroy();

    /**
     * @brief Set all elements to zero
     *
     * @return int
     */
    int Clear();

    // Get sth
    bool isTreeEmpty();
    int TreeDepth();
    tnode &Root();
    tnode &Parent(tnode &_child);
    tnode &Lchild(tnode &src);
    tnode &Rchild(tnode &src);

    // modify the tree
    int Changenode(const Tree &te, int _old, int _new);
    int InsertNode(int _id, tnode &src, bool flag);
    int DelTree(Tree &src, tnode &dst, int n);

    // Traverse
    void PreOrderTra(tnode &next);
    void MidOrderTra(tnode &next);
    void PostOrderTra(tnode &next);

    // Traverse for search
    bool MidOrderTra(tnode &next, tnode &src, tnode &res);

  private:
    static std::shared_ptr<tnode> HEAD;
    int depth = 0;
};

}

#endif