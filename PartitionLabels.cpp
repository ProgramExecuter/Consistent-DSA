class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        
        //Store last idx of each character
        int len = s.size();
        for(int i=0; i<len; ++i)
        {
            mp[s[i]] = i;
        }
        
        vector<int> ans;
        
        // minP => lastIdx of current Partition(can be increased)
        // start_idx => starting idx of current partition
        int minP = 0, start_idx=0;
        for(int i=0; i<len; ++i)
        {
            // If the current character has higher last idx
            // then minimum partition size is increased
            minP = max(minP, mp[s[i]]);
            
            
            //Marks end of current partition
            if(i == minP)
            {
                ans.push_back(i-start_idx+1);
                start_idx = minP+1;
            }
        }
        return ans;
    }
};