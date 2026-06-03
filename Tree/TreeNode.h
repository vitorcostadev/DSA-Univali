#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include <iostream>

template<typename T>
struct TreeNode{
    T element;
    TreeNode<T> *left, *right;
};

struct HNode{
    unsigned frequency;
    char character;
    
    bool operator<(const HNode& other) const {
        return frequency < other.frequency;
    }
    
    bool operator>(const HNode& other) const {
        return frequency > other.frequency;
    }
    
    bool operator==(const HNode& other) const {
        return frequency == other.frequency;
    }
    
    bool operator!=(const HNode& other) const {
        return frequency != other.frequency;
    }
};

inline std::ostream& operator<<(std::ostream& os, const HNode& node) {
    if(node.character == '\0'){
        // Nó interno
        os << "[*:" << node.frequency << "]";
    } else {
        // Nó folha
        os << "[" << node.character << ":" << node.frequency << "]";
    }
    return os;
}

#endif