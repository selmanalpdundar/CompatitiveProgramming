int findMax(struct Node *root,int &result)
{
    if(root == nullptr)
    {
        return 0;
    }
    int leftPath = findMax(root->left,result);
    
    int rightPath = findMax(root->right,result);

    int max_single = max(max(leftPath, rightPath) + root->data, root->data);
    
    int max_top = max(max_single, leftPath + rightPath + root->data);
    
    result = max(result, max_top);
    
    return max_single;
}

int maxPathSum(struct Node *root)
{

    int result = INT_MIN;
    findMax(root,result);
    return result;
}
