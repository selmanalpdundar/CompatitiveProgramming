
//Problem wants only isBST function
bool isBST(Node* root, Node* low=NULL, Node* high=NULL)
{
    if (root == NULL)
        return true;
    
    if (low != NULL && root->data < low->data)
        return false;
    
    if (high!= NULL && root->data > high->data)
        return false;

    return isBST(root->left, low, root) && isBST(root->right, root, high);
}

bool isBST(Node* root) {
    isBST(root,NULL,NULL);
}
