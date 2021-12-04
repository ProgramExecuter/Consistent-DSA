class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If 0 or 1 Nodes
        if(!head or !head->next) return head;
        
        //Swapping part happens here
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next); 
        temp->next = head;

        return temp;
    }
};