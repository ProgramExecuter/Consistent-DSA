class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1, curr = 1;
        int len = nums.size();
        
        // Check for current and previous element
        for(int i = 1; i < len; ++i) {
            // If current ELE is greater than previous
            // then ++curr
            if(nums[i] > nums[i-1])     ++curr;
            // Else start from next ELE
            else    curr = 1;
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};