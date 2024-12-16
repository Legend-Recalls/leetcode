class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* current = dummy;

        while (current && current->next) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; 
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};