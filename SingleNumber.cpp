class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Starting XOR value
        int ans = 0;
        // Visit each element
        for(int i=0; i<nums.size(); ++i) {
            // When Xor-ing two numbers with same values
            // then they cancel each other
            // thus we are left with 1 number that's the answer
            ans ^= nums[i];
        }
        return ans;
    }
};