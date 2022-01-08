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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        
        int lowCrit = INT_MAX, prevCrit = -1, pos = 1, ansMin = INT_MAX, critCnt = 0;
        
        // Move to 2nd node
        // So that we have a previous node
        prev = head;
        curr = curr->next;
        
        // Perform till second last node
        // SO that we have a next node
        while(curr->next) {
            // Critical Point
            if( 
                (curr->val > prev->val  && curr->val > curr->next->val) ||
                (curr->val < prev->val  && curr->val < curr->next->val)
            ) {
                // Get minimum pos of critical point
                lowCrit = min(lowCrit, pos);
                // If there was a critical point before
                // then check if distance b/w two is lower than ansMin
                if(prevCrit > 0) {
                    ansMin = min(ansMin, (pos-prevCrit));
                }
                // Make current Critical pos to be prevCrit
                prevCrit = pos;
                
                ++critCnt;
            }
            // Move to next node
            ++pos;
            prev = curr;
            curr = curr->next;
        }
        
        vector<int> ans(2);
        ans[0] = -1;    ans[1] = -1;
        
        // If no. of critical points < 2
        // return {-1, -1}
        if(critCnt < 2) {
            return ans;
        }
        
        // min distance b/w critical points
        ans[0] = ansMin;
        // max distance b/w critical points
        ans[1] = prevCrit - lowCrit;
        
        return ans;
    }
};