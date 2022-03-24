// Time Complexity - O(n)
// Space Complexity - O(1), O(n) - call stack

class Solution {
public:
    pair<bool, int> checkBalance(TreeNode* root) {
        if(root == NULL)    return {true, 0};
        
        pair<bool, int> left, right;
        
        left  = checkBalance(root->left);
        right = checkBalance(root->right);
        
        int height = max(left.second, right.second) + 1;
        
        // If any of sub-tree isn't balanced then tree isn't balanced
        if(!left.first  ||  !right.first)
            return {false, 0};
        
        // The heights of left & right sub-trees are not more than 1 apart
        if(abs(left.second - right.second) <= 1) {
            return {true, height};
        }
        // Height of sub-trees not same
        else {
            return {false, height};
        }
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
};