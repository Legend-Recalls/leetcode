class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // Empty list or single node with no next pointer
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;         // Move slow pointer by 1 step
            fast = fast->next->next;  // Move fast pointer by 2 steps
            
            if (slow == fast) {       // Cycle detected
                return true;
            }
        }
        
        return false; // No cycle detected
    }
};
