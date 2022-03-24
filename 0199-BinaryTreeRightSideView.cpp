// Time Complexity - O(n)
// Space Complexity - O(logn)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        // If no node are present in Tree
        if(!root)       return ans;
        
        int currLevel = -1;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        
        while(!st.empty()) {
            TreeNode* curr = st.top().first;
            int level = st.top().second;
            
            st.pop();       // Pop the top node from stack
            
            if(level > currLevel) {
                ans.push_back(curr->val);           // Push the current element to stack       
                currLevel = max(level, currLevel);  // Increase the level
            }
            
            if(curr->left)      st.push({curr->left,  level+1});
            if(curr->right)     st.push({curr->right, level+1});
        }
        
        return ans;
    }
};