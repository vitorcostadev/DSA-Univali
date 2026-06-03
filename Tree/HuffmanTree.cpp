#include "BinarySearchTree.cpp"
#include "List.h"
using namespace std;

class HuffmanTree : public BinarySearchTree<HNode>{
    private:
        List<HNode> list;
        List<TreeNode<HNode>*> treeNodes;

        HNode* firstTwoElements(){
            if(list.size() < 2) return NULL;
            HNode* _ = new HNode[2];
            _[0] = list.get(0);
            _[1] = list.get(1);
            return _;
        }

        // Encontrar índice dos dois menores nós
        void findTwoSmallest(int &idx1, int &idx2){
            idx1 = 0;
            idx2 = 1;
            
            if(treeNodes.get(idx1)->element.frequency > treeNodes.get(idx2)->element.frequency){
                swap(idx1, idx2);
            }
            
            for(int i = 2; i < treeNodes.size(); i++){
                if(treeNodes.get(i)->element.frequency < treeNodes.get(idx1)->element.frequency){
                    idx2 = idx1;
                    idx1 = i;
                }else if(treeNodes.get(i)->element.frequency < treeNodes.get(idx2)->element.frequency){
                    idx2 = i;
                }
            }
        }

        void addElement(HNode element, TreeNode<HNode> *&node){
            if(node == NULL){
                node = new TreeNode<HNode>();
                node->element = element;
                node->left = node->right = NULL;

                this->cardinalidade++;
            }else if(element.frequency < node->element.frequency){
                addElement(element, node->left);
            }else{
                addElement(element, node->right);
            }
        }
    public:
        HuffmanTree() : BinarySearchTree<HNode>(){}

        int compareTo(HNode o, HNode a) override{
            if(o == a) return 0;
            if(o > a) return 1;
            return -1;
        }
        
        void addToTree(HNode element) {this->addElement(element, this->root);}

        void makeStringFrequency(string text){
            for(unsigned i = 0; i<text.length(); i++){
                char currentChar = text.at(i);
                bool found = false;
                
                for(int k = 0; k < list.size(); k++){
                    if(list.get(k).character == currentChar){
                        found = true;
                        break;
                    }
                }
                
                if(!found){
                    HNode node = {0u, currentChar};
                    for(unsigned j = 0; j<text.length(); j++){
                        if(currentChar == text.at(j)){
                            node.frequency++;
                        }
                    }
                    list.add(node);
                }
            }

            list.sort();
            
            // Criar TreeNodes iniciais para cada HNode
            for(int i = 0; i < list.size(); i++){
                TreeNode<HNode>* node = new TreeNode<HNode>();
                node->element = list.get(i);
                node->left = NULL;
                node->right = NULL;
                treeNodes.add(node);
            }
        }

        void makeTree(){
            while(treeNodes.size() > 1){
                int idx1, idx2;
                findTwoSmallest(idx1, idx2);
                
                TreeNode<HNode>* left = treeNodes.get(idx1);
                TreeNode<HNode>* right = treeNodes.get(idx2);
                
                TreeNode<HNode>* parent = new TreeNode<HNode>();
                parent->element.frequency = left->element.frequency + right->element.frequency;
                parent->element.character = '\0';
                parent->left = left;
                parent->right = right;
                
                if(idx1 > idx2){
                    treeNodes.remove(idx1);
                    treeNodes.remove(idx2);
                }else{
                    treeNodes.remove(idx2);
                    treeNodes.remove(idx1);
                }
                treeNodes.add(parent);
            }
            
            if(treeNodes.size() == 1){
                this->root = treeNodes.get(0);
                this->cardinalidade = 1;
            }
        }

        List<HNode>& getList() {return this->list;}
        TreeNode<HNode>* getRoot(){return this->root;}
        ~HuffmanTree() override {
        }

};