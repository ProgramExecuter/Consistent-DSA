class Solution {
public:
    int firstUniqChar(string s) {
        // Create a frequency array
        vector<int> freq(26, 0);
        
        // First occurence of character
        vector<int> idx(26, -1);
        
        for(int i=0; i<s.size(); ++i) {
            char ch = s[i];
            
            ++freq[ch-'a'];
            // If its appearing for first time
            // then save its index
            if(idx[ch-'a'] == -1)
                idx[ch-'a'] = i;
        }
        
        int ans = INT_MAX;
        for(int i=0; i<26; ++i) {
            // If it appeared only once
            // find the minimum index among these characters
            if(freq[i] == 1) {
                ans = min(ans, idx[i]);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};