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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {        
        ListNode *currl1 = list1, *currl2 = list2;
        int cnt = 0;
        
        
        // Find (a-1)th node
        while(cnt < a-1) {
            currl1 = currl1->next;
            ++cnt;
        }
        
        
        // Linking start
        ListNode* tmp = currl1->next;
        currl1->next  = list2;
        currl1        = tmp;
        ++cnt;
        
        
        // Deleted linked list
        ListNode* delStart = currl1->next;
        
        
        // Find the (b-1)th node
        while(cnt < b) {
            currl1 = currl1->next;
            ++cnt;
        }
        
        
        // reach last node of list2
        while(currl2->next) {
            currl2 = currl2->next;
        }
        
        
        // Last node of 'l2' points to next of
        // node with value of 'b'
        currl2->next = currl1->next;
        
        
        // Delete link from last deleted node
        currl1->next = NULL;

        
        return list1;
    }
};