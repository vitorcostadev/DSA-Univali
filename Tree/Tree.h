#include "TreeNode.h"

template<typename T>
class Tree {
protected:
    TreeNode<T>* root;
    int cardinalidade;

public:
    Tree() : root(NULL), cardinalidade(0) {}
    virtual ~Tree() {}

    virtual void add(T element) = 0;
    virtual void erase(T element) = 0;
    virtual bool contains(T element) = 0;
    virtual void destroy() = 0;
    int size() {return cardinalidade;}
};