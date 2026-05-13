#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

template<typename T>
struct TreeNode{
    T element;
    TreeNode<T> *left, *right;
};

#endif