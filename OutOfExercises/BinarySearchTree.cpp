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
        
        if(root == NULL) return;
        
        Node *current = root;
        Node *parent = NULL;
        bool isLeft = false;
        
        while(current != NULL){
           
            if(current->value == value) break;
        
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
        
        if(current == NULL) return;
        
        if(current->left == NULL && current->right == NULL){
            free(current);
            if(isLeft) parent->left = NULL;
            else parent->right = NULL;
            
        } else if(current->left != NULL && current->right == NULL){
           
            if(isLeft) parent->left = current->left;
            else parent->right = current->left;
      
        } else if(current->left == NULL && current-> right != NULL){
           
            if(isLeft) parent->left = current->right;
            else current->right = current->right;

        }else if( current->left != NULL && current->right != NULL){
            
            
        }
    }
    
    
    Node *lookup(int value){
        
        Node *current = root;
        
        if(current == NULL) return NULL;
        
        while(current != NULL){
            
            if(current->value == value) return current;
            
            if(current->value > value) current = current->left;
            
            if(current->value < value) current = current->right;
            
        }
        return NULL;
    }
    
    
    
    
    void print(){
        print(root);
    }
    
    Node *min(){
        Node *current = root;
        
        if(current == NULL) return NULL;
    
        while(current->left != NULL) current  = current->left;
        
        return current;
        
        
    }
    
    
    Node *max(){
        Node *current = root;
        
        if(current == NULL) return NULL;
        
        while(current->right != NULL)  current = current->right;
        
        return current;
    }
    
    
    // inorder
    void print(Node *root){
        
        if(root == NULL) return;
        
        if(root->left != NULL) print(root->left);
        
        std::cout<<root->value<<std::endl;
        
        if(root->right != NULL) print(root->right);
    }
    
    
    
    
};

int main(){
    
    BinarySearchTree *bst = new BinarySearchTree();
    /*
                    100
                   /    \
                 10      200
                /  \    /   \
               5    11 201  400
              / \
             4   6
            /
           3
     */
    
    bst->insert(100);
    bst->insert(10);
    bst->insert(5);
    bst->insert(11);
    bst->insert(200);
    bst->insert(201);
    bst->insert(400);
    bst->insert(4);
    bst->insert(3);
    bst->insert(6);
    
    bst->deleteNode(5);
    //bst->deleteNode(100)
    //bst->deleteNode(200);
    //bst->deleteNode(11);
    
    
   // bst->print();
    
    Node *node  = bst->lookup(5);
    
    std::cout<<"Lookup(5) : "<<node->value<<std::endl;
    std::cout<<"Min() : "<<bst->min()->value<<std::endl;
    std::cout<<"Max() : "<<bst->max()->value<<std::endl;
    
    
    return 0;
}
