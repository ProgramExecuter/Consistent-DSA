class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        if(n == 0) {
            return ans;
        }
        
        ans[1] = 1;
        
        // Pattern
        // ans[i] = ans[i/2]      if ( i % 2 == 0 )
        // ans[i] = ans[i/2]+1    if ( i % 2 == 1 )
        for ( int i = 2; i <= n; ++i ) {
            ans[i] = ans[i/2] + (i % 2);
        }
        
        return ans;
    }
};