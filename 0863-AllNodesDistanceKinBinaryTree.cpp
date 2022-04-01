// Time Complexity - O(N + N)
// Space Complexity - O(N + N), for 'map' and 'ans'

class Solution {
public:
    void findAndMap(TreeNode* root, map<TreeNode*, TreeNode*> &mp) {
        if(!root)       return;
        
        if(root->right)     mp[root->right] = root;     // Map left  node to its parent
        if(root->left)      mp[root->left]  = root;     // Map right node to its parent
        
        findAndMap(root->left,  mp);
        findAndMap(root->right, mp);
    }
    void solve(TreeNode* root, vector<int> &ans, map<TreeNode*, TreeNode*> &mp, TreeNode* caller, int dist) {
        if(!root)       return;
        
        if(dist == 0)   ans.push_back(root->val);      // K-distance from 'target'
        
        if(mp.find(root) != mp.end()) {         // Parent exists
            if(caller != mp[root]) {            // If parent isn't caller
                solve(mp[root], ans, mp, root, dist-1);
            }
        }
        
        if(root->left != caller)                        // If left-child isn't caller
            solve(root->left, ans, mp, root, dist-1);
        
        if(root->right != caller)                       // If right-child isn't caller
            solve(root->right, ans, mp, root, dist-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        findAndMap(root, mp);           // Find the node, and map (nodes -> parent)
        
        vector<int> ans;
        solve(target, ans, mp, NULL, k);
        
        return ans;
    }
};