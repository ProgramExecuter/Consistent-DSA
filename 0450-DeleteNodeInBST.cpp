// Time Complexity - O(logN)
// Space Complexity - O(logN), call stack

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if(!root->left && !root->right) return NULL;
            if(!root->right)                return root->left;
            if(!root->left)                 return root->right;
            else {
                TreeNode* suc = root->right;        // Find successor
                while(suc->left) {
                    suc = suc->left;
                }
                root->val = suc->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        
        return root;
    }
};