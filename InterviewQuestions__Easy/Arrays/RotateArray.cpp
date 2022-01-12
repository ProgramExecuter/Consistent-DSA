class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k % n;
        
        // reverse last K elements
        reverse(nums.begin()+n-k, nums.end());
        
        // reverse all remaining elements
        reverse(nums.begin(), nums.begin()+n-k);
        
        // reverse all the elements
        reverse(nums.begin(), nums.end());
    }
};
