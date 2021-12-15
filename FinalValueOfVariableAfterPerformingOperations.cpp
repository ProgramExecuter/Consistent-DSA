class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        
        for (string opr : operations) {
            if(opr[1] == '+') {
                ++ans;
            }
            else {
                --ans;
            }
        }
        
        return ans;
    }
};