class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        
        for(int a = 0; a < 2; ++a) {
            for(int i : nums) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};