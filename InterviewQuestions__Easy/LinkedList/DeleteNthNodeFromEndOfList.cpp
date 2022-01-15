/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        
        // Move 'fast' pointer N steps ahead
        while(n--) {
            fast = fast->next;
        }
        
        // Useful for storing HEAD
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        
        // Move to next while 'fast' is not NULL
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* del = slow->next;
        
        slow->next = slow->next->next;
        
        // Free the Node
        delete del;
        
        return dummy->next;
    }
};