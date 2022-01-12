class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Insert the elements in map
        unordered_map<int, int> mp;
        
        // Find the right element
        for(int i=0; i<n; ++i) {
            // Find the right elements
            if(mp.find(target-nums[i]) != mp.end()) {
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        
        return {};
    }
};