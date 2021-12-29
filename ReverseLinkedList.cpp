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
    ListNode* reverseList(ListNode* head) {
        // If 0 or 1 nodes
        // no need of reversing
        if(!head || !head->next) {
            return head;
        }
        
        ListNode *curr = head, *prev = NULL;
        
        // Reverse
        while(curr->next) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        curr->next = prev;
        // Make last node as 'head'
        head = curr;
        
        return head;
    }
};