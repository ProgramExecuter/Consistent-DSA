class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                //more than one element out of order
                if(count == 1) {
                    return false;
                }
                
                // Found one out of order element 
                // Is i-2 th element greater than i th element?
                // if yes then we have to delete i th element
                // (simply replace it by i-1 element).
                if( i >= 2 && nums[i-2] >= nums[i]) {
                    nums[i] = nums[i-1];
                }
                count++;
            }            
        }
        return count <= 1;
    }
};