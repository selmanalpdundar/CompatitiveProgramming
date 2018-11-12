#include <iostream>

class Node{
public:
    int value;
    Node *left;
    Node *right;

public:
    Node(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree{
    
    Node *root;
public:
    void insert(int value){
        if(root == NULL){
            root = new Node(value);
            return;
        }
        
        Node *current = root;
        Node *parent = current;
        
        while(current != nullptr){
            parent = current;
            if(current->value >= value){
                current = current->left;
            } else{
                current = current->right;
            }
        }
        if(parent->value >= value){
            parent->left = new Node(value);
        } else {
            parent->right = new Node(value);
        }
        
    }
    
    void deleteNode(int value){
        
        if(root == NULL){
            return;
        }
        
        Node *current = root;
        Node *parent = NULL;
        bool isLeft = false;
        
        while(current != NULL){
           
            if(current->value == value){
                break;
            }
        
            if(current->value > value){
                parent = current;
                current = current->left;
                isLeft = true;
            }else{
                parent = current;
                current = current->right;
                isLeft = false;
            }
        }
        
        if(current == NULL){
            return;
        }
        
        if(current->left == NULL && current->right == NULL){
            free(current);
            if(isLeft){
                parent->left = NULL;
            } else{
                parent->right = NULL;
            }
        } else if(current->left != NULL && current->right == NULL){
            parent->left = current->left;
        } else if(current->left == NULL && current-> right != NULL){
            parent->right = current->right;
        }else if( current->left != NULL && current->right != NULL){
            
        }
    }
    
    
    
    void print(){
        print(root);
    }
    
    void print(Node *root){
        
        if(root == NULL){
            return;
        }
        
        if(root->left != NULL){
            print(root->left);
        }
        std::cout<<root->value<<std::endl;
        
        if(root->right != NULL){
            print(root->right);
        }
    }
    
};

int main(){
    
    BinarySearchTree *bst = new BinarySearchTree();
    
    bst->insert(100);
    bst->insert(10);
    bst->insert(5);
    bst->insert(1);
    bst->insert(200);
    
    bst->print();
    
    return 0;
}
