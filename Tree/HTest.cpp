#include <iostream>
#include "HuffmanTree.cpp"
using namespace std;

int main(){
    HuffmanTree tree;
    tree.makeStringFrequency("Vai tomando fdp do caralho");
    cout << "Frequency list size before makeTree: " << tree.getList().size() << endl;
    
    cout << "\nLista de frequencias (ordenada):" << endl;
    for(int i = 0; i < tree.getList().size(); i++){
        cout << tree.getList().get(i).character << ": " << tree.getList().get(i).frequency << endl;
    }
    
    tree.makeTree();
    
    cout << "\nFrequency list size after makeTree: " << tree.getList().size() << endl;
    
    TreeNode<HNode>* root = tree.getRoot();
    if(root != NULL){
        cout << "Root exists. Root frequency: " << root->element.frequency << endl;
        cout << "\nArvore em pre-ordem:" << endl;
        tree.print();
    } else {
        cout << "Root is NULL" << endl;
    }
    
    return 0;
}