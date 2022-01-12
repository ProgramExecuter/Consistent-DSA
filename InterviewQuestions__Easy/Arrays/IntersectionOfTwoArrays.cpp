class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        // Count the occurences of elements
        unordered_map<int, int> cnt;
        for(int ele : nums1) {
            ++cnt[ele];
        }
        
        for(int ele : nums2) {
            // If there's an occurence of element
            // push it to 'ans' and reduce its count by 1
            if(cnt[ele] > 0) {
                ans.push_back(ele);
                --cnt[ele];
            }
        }
        
        return ans;
    }
};