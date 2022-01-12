class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), rem = 1;
        
        vector<int> ans;
        
        for(int i=n-1; i>=0; --i) {
            // Current total of remainder and digit
            int num = digits[i]+rem;
            
            // Push the digit in 'ans'
            ans.push_back(num%10);
            
            // Remainder after operation
            rem = num / 10;
        }
        
        // If remainder is left then push it to 'ans'
        if(rem > 0) {
            ans.push_back(rem);
        }
        
        // Reverse the 'ans' to get real answer
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};