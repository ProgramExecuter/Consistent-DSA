class Solution {
public:
    //Check if string is palindrome
    bool isPalin(string s) {
        int len = s.size();
        
        for(int i=0, j=len-1; i < j; ++i, --j)
        {
            if(s[i] != s[j])
                return false;
        }
        
        return true;
    }
    bool isPalindrome(string s) {
        string resStr;
        for(char ch : s)
        {
            if(ch>='A' && ch<='Z')
            {
                resStr += char(ch+32);
            }
            else if(
                (ch>='a' && ch<='z') ||
                (ch>='0' && ch<='9')
            )
                resStr += ch;
        }
        return isPalin(resStr);
    }
};