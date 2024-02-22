 struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
    
}