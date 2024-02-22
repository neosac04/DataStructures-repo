struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *nextPair = swapPairs(head->next->next);
    struct ListNode *newHead = head->next;
    head->next = nextPair;
    newHead->next = head;

    return newHead;
    
}