bool isPalindrome(struct ListNode* head) {
    int values[100000];
    int length = 0;
    struct ListNode* current = head;

    while (current) {
        values[length++] = current->val;
        current = current->next;
    }

    int left = 0, right = length - 1;
    while (left < right) {
        if (values[left] != values[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
