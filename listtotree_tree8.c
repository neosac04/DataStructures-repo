 void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = NULL; // Split the list into two halves
    }

    return slow;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode* mid = findMiddle(head);

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;

    if (head == mid) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
    
}