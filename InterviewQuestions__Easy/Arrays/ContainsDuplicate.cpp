class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        
        // Visit every element
        for(int i : nums)
        {
            // If the element is in the set
            // It appeared once
            if(st.find(i) != st.end())
                return true;
            // Insert the element in the set
            st.insert(i);
        }
        return false;
    }
};