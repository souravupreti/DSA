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
    int help(TreeNode* root,int &maxx){
        if(!root){
            return 0;
        }
        int left=help(root->left,maxx);
        left=max(0,left);
        int right=help(root->right,maxx);
        right=max(0,right);
        maxx=max(left+right+root->val,maxx);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxx=INT_MIN;
        help(root,maxx);
        return maxx;
    }
};