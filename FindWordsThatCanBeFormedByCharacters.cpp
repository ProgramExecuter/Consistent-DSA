class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Count individual count of characters in CHARS 
        int cntChar[26] = {0};
        for(char i : chars) {
            ++cntChar[i-'a'];
        }
        
        int ans = 0;
        int len = words.size();
        
        for(int i = 0; i < len; ++i) {
            // Count individual count of characters in each word
            int tmpChars[26] = {0};
            
            for(char j : words[i]) {
                ++tmpChars[j-'a'];
            }
            
            // If all 26 counts matches then add it to ANS
            int j = 0;
            for(; j < 26; ++j) {
                if(tmpChars[j] > 0 && tmpChars[j] > cntChar[j]) {
                    break;
                }
            }
            if(j == 26) {
                ans += words[i].size();
            }
        }
        return ans;
    }
};