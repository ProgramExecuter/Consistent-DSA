class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroP = 0, n = nums.size();
        
        for(int i=0; i<n; ++i) {
            // If the element != 0
            // then swap with zeroPointer
            // and move zero Pointer to next index
            if(nums[i] != 0) {
                swap(nums[zeroP], nums[i]);
                ++zeroP;
            }
        }
        
    }
};