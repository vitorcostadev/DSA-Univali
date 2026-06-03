#include <iostream>
#include "Tree.h"
#include "List.h"

template<typename T>
class BinarySearchTree : public Tree<T>, public Compare<T>{
    private:
        void addElement(T element, TreeNode<T> *&node){
            if(node == NULL){
                node = new TreeNode<T>();
                node->element = element;
                node->left = node->right = NULL;

                this->cardinalidade++;
            }else if(element < node->element){
                addElement(element, node->left);
            }else{
                addElement(element, node->right);
            }
        }

        void printTree(TreeNode<T> *node){
            if(node == NULL) return;
            
            std::cout << node->element << " "; 
            printTree(node->left);               
            printTree(node->right);              
        }

        void removeElement(T element, TreeNode<T> *&node, TreeNode<T> *&aux){
            if(node == NULL) return;
            
            if(element < node->element){
                removeElement(element, node->left, aux);
            }else if(element > node->element){
                removeElement(element, node->right, aux);
            }else{
                aux = node;
                if(aux->right == NULL){
                    node = aux->left;
                    delete aux;
                    this->cardinalidade--;
                }else if(aux->left == NULL){
                    node = aux->right;
                    delete aux;
                    this->cardinalidade--;
                }else{
                    removeElement(element, aux->right, aux);
                }
            }
        }

        void destroyTree(TreeNode<T> *&r){
            if(r != NULL){
                destroyTree(r->left);
                destroyTree(r->right);
                delete(r);
                r = NULL;
            }
        }

        void destroy() override{
            destroyTree(this->root);
            this->root = NULL;
            this->cardinalidade = 0;
        }

        T sumRecursive(TreeNode<T> *root){
            if(root == NULL) return 0;
            return root->element 
            + sumRecursive(root->left) 
            + sumRecursive(root->right);
            
        }
    public:
        BinarySearchTree() : Tree<T>(){}

        int compareTo(T a, T o) override{
            if(a == o) return 0;
            if(a > o) return 1;
            return -1;
        }
        void add(T element) override {addElement(element, this->root);}

        void erase(T element) override{
            if(!isEmpty()) {
                TreeNode<T> *aux = NULL;
                removeElement(element, this->root, aux);
            }
        }
        bool contains(T element) noexcept override {
            TreeNode<T> *aux = this->root;
            while(aux != NULL && aux->element != element){
                if(element < aux->element) {aux = aux->left;}
                else {aux = aux->right;}
            }

            return aux != NULL;

        }
        bool isEmpty() noexcept {return this->size() == 0;}
        void clear() noexcept {this->destroy(); }

        void print(){
            printTree(this->root);
            std::cout << std::endl;

        }

        T sum(){
            return sumRecursive(this->root);
        }
        ~BinarySearchTree() override {destroy();}

};