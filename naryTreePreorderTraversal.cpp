/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root)   return ans;
        
        stack<Node*> tmpStack;
        tmpStack.push(root);
        
        while(!tmpStack.empty()) {
            Node* curr = tmpStack.top();
            tmpStack.pop();
            ans.push_back(curr->val);
            int len = curr->children.size()-1;
            for(int i=len; i>=0; --i) {
                tmpStack.push(curr->children[i]);
            }
        }
        
        return ans;
    }
};