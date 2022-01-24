class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> palinRange(n, vector<bool>(n, false));
        
        // All string with 1 size are palindrome
        for(int i=0; i<n; ++i)
            palinRange[i][i] = true;
        
        // We check for sizes 2 -> n
        for(int size=1; size<n; ++size)
        {
            for(int i=0; i<n-size; ++i)
            {
                // If border characters are same and string between them is palindrome
                // then this range is palindrome
                if( size==1  &&  s[i]==s[i+size] )
                    palinRange[i][i+size] = true;
                if( size>1  &&  s[i]==s[i+size]  &&  palinRange[i+1][i+size-1] )
                    palinRange[i][i+size] = true;
            }
        }
        
        int st = 0, en = 0;
        for(int size=n-1; size>=0; --size)
        {
            for(int i=0; i<n-size; ++i)
            {
                if(palinRange[i][i+size])
                    return s.substr(i, size+1);
            }
        }
        
        return s.substr(0,1);
    }
};