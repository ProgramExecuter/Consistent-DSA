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
    ListNode* oddEvenList(ListNode* head) {
        // If 0 or 1 nodes
        // return 'head'
        if(!head || !head->next)    return head;
        
        ListNode *odd = head, *even = head->next, *tmp = head->next;
        
        while(even && even->next) {
            // Make separate LLs of odd and even elements
            odd->next  = odd->next->next;
            even->next = even->next->next;
            
            odd  = odd->next;
            even = even->next;
        }
        
        // Join end of 'odd' LL to start of 'even' LL
        odd->next = tmp;
        
        return head;
    }
};