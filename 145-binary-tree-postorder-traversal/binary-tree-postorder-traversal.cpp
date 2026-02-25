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
        stack<TreeNode* >st;
        vector<int>ans;
        TreeNode * curr=root;
        while(curr||!st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode * right=st.top()->right;
                if(right==NULL){
                    TreeNode *temp=st.top();
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty()&&temp==st.top()->right){
                        temp=st.top();
                        ans.push_back(temp->val);
                    st.pop();
                    }
                }
                else{
                    curr=right;
                }
            }
        }
        return ans;
    }
};