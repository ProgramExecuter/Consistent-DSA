class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, curr = 0;
        
        for(char ch : s) {
            // If there's a character then  ++curr
            if((ch >= 'a'  &&  ch <= 'z') ||
                (ch >= 'A'  &&  ch <= 'Z'))
            {
                ++curr;
            }
            // else there's a white space
            else
            {
                // If the size of word is > 0 then only considered word
                if(curr > 0) {
                    ans = curr;
                }
                curr = 0;
            }
        }
        // For final word without trailing space
        if(curr > 0) {
            ans = curr;
        }
        
        return ans;
    }
};