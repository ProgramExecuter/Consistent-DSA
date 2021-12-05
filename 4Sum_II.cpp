class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> mp;

        //Storing all possible sums of pairs of first 2 arrays
        for (int a : nums1)
            for (int b : nums2)
                mp[a+b]++;
        // Finding the pairs which can compare(-vely) to previous pairs
        // thus prev Pairs + these Pairs == 0;
        for (int c : nums3)
            for (int d : nums4)
                res += mp[-c-d];
        return res;
    }
};