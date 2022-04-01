// Time Complexity - O(logN)
// Space Complexity - O(logN), call stack

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *tmp = root, *newNode = new TreeNode(val);
        
        if(!root)   return newNode;         // If no node present, make new node 'root'
        
        while(tmp) {
            if(tmp->val > val) {            // This new node should be inserted on left
                if(tmp->left == NULL) {     // Can be inserted on left
                    tmp->left = newNode;
                    break;
                }
                tmp = tmp->left;            // Go to left-subtree
            }
            else {
                if(tmp->right == NULL) {    // This new node should be inserted on right
                    tmp->right = newNode;   // Can be inserted on left
                    break;
                }
                tmp = tmp->right;           // Go to right-subtree
            }
        }
        
        return root;
    }
};