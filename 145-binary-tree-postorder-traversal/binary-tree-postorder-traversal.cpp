/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode* >s;
        stack<TreeNode*>st;
        s.push(root);
        vector<int>ans;
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            st.push(temp);
            if(temp->left){
                s.push(temp->left);
            }
            if(temp->right){
                s.push(temp->right);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top()->val);
            st.pop();
        }
        return ans;
        
    }
};