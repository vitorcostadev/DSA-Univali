#include <iostream>
#include "BinarySearchTree.cpp"

using namespace std;

int main(){
    BinarySearchTree<int> tree;

    tree.add(10);
    tree.add(5);
    tree.add(15);
    cout << "Tree contains 10: " << tree.contains(10) << endl;
    cout << "Tree contains 5: " << tree.contains(5) << endl;
    cout << "Tree contains 15: " << tree.contains(15) << endl;
    cout << "Tree size: " << tree.size() << endl;
    tree.erase(5);
    cout << "Tree contains 5 after erasing: " << tree.contains(5) << endl;
    cout << "Tree size after erasing 5: " << tree.size() << endl;
    tree.clear();
    cout << "Size after clear: " << tree.size() << endl;
    return 0;
}