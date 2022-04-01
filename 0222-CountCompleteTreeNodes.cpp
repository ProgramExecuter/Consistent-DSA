// Time Complexity - O(logN)
// Space Complexity - O(N), for call stack

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        
        int lh = 0, rh = 0;
        
        TreeNode* tmp = root;
        while(tmp->left) {          // Calculate left-subtree height
            ++lh;
            tmp = tmp->left;
        }
        
        tmp = root;
        while(tmp->right) {         // Calculate right-subtree height
            ++rh;
            tmp = tmp->right;
        }
        
        if(lh == rh) {                  // Complete Binary Tree, since left-height = right-height
            return (pow(2, lh+1)-1);    // No. of elements of complete BT
        }
        
        // Not a complete Binary Tree
        int left  = countNodes(root->left);
        int right = countNodes(root->right);
        
        return (1 + left + right);      // No of elements = cnt of left-ele + cnt of right-ele + 1(root element)
    }
};