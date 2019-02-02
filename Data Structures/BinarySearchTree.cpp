#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
public:
    long long int value;
    Node *left;
    Node *right;
    Node *parent;
    
public:
    Node(long long int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class BinarySearchTree{
    
private:
    Node *root;
    
public:
    void insert(int value);
    void deleteNode(int value);
    Node* lookup(int value);
    Node* min();
    Node* min(Node *startPoint);
    Node* max();
    Node* max(Node *startPoint);
    Node* successor(Node *element);
    Node* predecessor(Node *element);
    bool isBST();
    void BFS(Node *element);
    void BFS();
    void inorder();
    void inorder(Node *element);
    void preorder();
    void preorder(Node *element);
    void postorder();
    void postorder(Node *element);
    void print();
    void print(Node *element);
    void eulerTour();
    void eulerTour(Node *element);
    
};

void BinarySearchTree::insert(int value){
    
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
        parent->left->parent = parent;
    } else {
        parent->right = new Node(value);
        parent->right->parent = parent;
    }
    
}

void BinarySearchTree::deleteNode(int value){
    
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
        if(isLeft)
            parent->left = NULL;
        else
            parent->right = NULL;
        
    } else if(current->left != NULL && current->right == NULL){
        
        if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
        
    } else if(current->left == NULL && current-> right != NULL){
        
        if(isLeft)
            parent->left = current->right;
        else
            current->right = current->right;
        
    }else if( current->left != NULL && current->right != NULL){
        Node *successor = this->successor(current);
        long long int temp = current->value;
        current->value = successor->value;
        successor->value = temp;
        this->deleteNode(value);
        
    }
}

Node* BinarySearchTree::lookup(int value){
    
    Node *current = root;
    
    if(current == NULL) return NULL;
    
    while(current != NULL){
        
        if(current->value == value) return current;
        
        if(current->value > value) current = current->left;
        
        if(current->value < value) current = current->right;
        
    }
    return NULL;
}

Node* BinarySearchTree::min(){
    return this->min(this->root);
}

Node* BinarySearchTree::min(Node *startPoint){
    Node *current = startPoint;
    
    if(current == NULL) return NULL;
    
    while(current->left != NULL) current  = current->left;
    
    return current;
}

Node* BinarySearchTree::max(){
    return max(this->root);
}

Node* BinarySearchTree::max(Node *startNode){
    Node *current = startNode;
    
    if(current == NULL) return NULL;
    
    while(current->right != NULL)  current = current->right;
    
    return current;
}

Node* BinarySearchTree::successor(Node *element){
    
    if(element->right != NULL)
    {
        return min(element->right);
    }
    else
    {
        Node *parent = element->parent;
        
        while(parent != NULL && element == parent->right){
            element = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

Node* BinarySearchTree::predecessor(Node *element){
    
    return NULL;
}

bool BinarySearchTree::isBST(){
    
    return false;
}

void BinarySearchTree::inorder(Node *element){
    
    if(element == NULL)
    { return; }
    inorder(element->left);
    cout<<element->value << " ";
    inorder(element->right);

    
}

void BinarySearchTree::inorder(){
    this->inorder(root);
}

void BinarySearchTree::preorder(){
    preorder(root);
}

void BinarySearchTree::preorder(Node *element){
    if(element == NULL)
    {
        return;
    }
    stack<Node*> stack;
    stack.push(element);
    
    while(!stack.empty())
    {
        Node *node = stack.top();
        stack.pop();
        
        cout<<node->value<<" ";
        if(node->right)
        {
            stack.push(node->right);
        }
        
        if(node->left)
        {
            stack.push(node->left);
        }
    }
    
}

void BinarySearchTree::postorder(){
    postorder(root);
}

void BinarySearchTree::postorder(Node *element){
    if(element == NULL)
    { return; }
    postorder(element->left);
    postorder(element->right);
    cout<<element->value << " ";
}
void BinarySearchTree::BFS()
{
    BFS(root);
}

void BinarySearchTree::BFS(Node *element)
{
    if(element == NULL)
    {
        return;
    }
    
    queue<Node*> queue;
    queue.push(element);
    
    
    while(!queue.empty())
    {
        Node *node = queue.front();
        queue.pop();
        cout<<node->value<< " ";
        if(node->left != NULL)
        {
            queue.push(node->left);
        }
        if(node->right != NULL)
        {
            queue.push(node->right);
        }
    }
    
}

void BinarySearchTree::print(Node *element)
{
    if(element == NULL) return;
    if(element->left != NULL) print(element->left);
    cout<<element->value<<endl;
    if(element->right != NULL) print(element->right);
}

void BinarySearchTree::print()
{
    print(this->root);
}


void BinarySearchTree::eulerTour()
{
    this->eulerTour(this->root);
}

void BinarySearchTree::eulerTour(Node *element)
{
    if(element!= nullptr)
    {
        cout<<element->value << " ";
        eulerTour(element->left);
        eulerTour(element->right);
        cout<<element->value<<" ";
        
    }
}

int main(){
    
    BinarySearchTree *bst = new BinarySearchTree();

    
    bst->insert(20);
    bst->insert(8);
    bst->insert(22);
    bst->insert(4);
    bst->insert(12);
    bst->insert(10);
    bst->insert(14);
    
    
    
    
    cout<<"Print BST"<<endl;
     bst->print();
    
    Node *node = bst->lookup(14);
   
    cout<<endl;
    
    cout<<"Lookup(14) : "<<node->value<<endl;
    cout<<"Min() : "<<bst->min()->value<<endl;
    cout<<"Max() : "<<bst->max()->value<<endl;
    
    cout<<endl;
    
    cout<<"Successor Of 8 : "<< bst->successor(bst->lookup(8))->value<<endl;
    cout<<"Successor Of 10 : "<< bst->successor(bst->lookup(10))->value<<endl;
    cout<<"Successor Of 14 : "<< bst->successor(bst->lookup(14))->value<<endl;
    
    cout<<endl;
    cout<<"Breadth First Search"<<endl;
    bst->BFS();
    
    cout<<endl<<endl;
    
    cout<<"Preorder"<<endl;
    bst->preorder();
    
    cout<<endl<<endl;
    
    cout<<"Posorder"<<endl;
    bst->postorder();
    
    cout<<endl<<endl;
    
    cout<<"Inorder"<<endl;
    bst->inorder();
    
    cout<<endl<<endl;
    cout<<"Euler Tour"<<endl;
    bst->eulerTour();
    
    cout<<endl<<endl;
    return 0;
}
