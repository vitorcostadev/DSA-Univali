#include <iostream>
#include <stdexcept>
#include "Tree.h"

template<typename T>
class BinarySearchTree : public Tree<T>{
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

        void removeElement(T element, TreeNode<T> *&node, TreeNode<T> *&aux){
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

        void removeElement(TreeNode<T> *&node, TreeNode<T> *&aux, T element){
            if(node->right != NULL){
                removeElement(node->right, aux, element);
            }else{
                aux->element = node->element;
                TreeNode<T> *temp = node;
                node = node->left;
                delete temp;
                this->cardinalidade--;
            }
        }

        void destroyTree(TreeNode<T> *&r){
            if(r != NULL){
                destroyTree(r->left);
                destroyTree(r->right);
                delete(r);
            }
        }

        void destroy(){
            destroyTree(this->root);
            this->cardinalidade = 0;
        }
    public:
        BinarySearchTree() : Tree<T>(){}

        void add(T element) override{addElement(element, this->root);}
        void erase(T element) override{
            if(!isEmpty()) {
                TreeNode<T> *aux = NULL;
                removeElement(element, this->root, aux);
            }
        }
        bool contains(T element) override {
            TreeNode<T> *aux = this->root;
            while(aux != NULL && aux->element != element){
                if(element < aux->element) {aux = aux->left;}
                else {aux = aux->right;}
            }

            return aux != NULL;

        }
        bool isEmpty() noexcept {return this->size() == 0;}
        ~BinarySearchTree(){destroy();}

};