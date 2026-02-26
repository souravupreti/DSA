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
    int help(TreeNode* root,int & maxx){
        if(!root){
            return 0;
        }
        int left=help(root->left,maxx);
        int right=help(root->right,maxx);
        maxx=max(left+right,maxx);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx=INT_MIN;
        help(root,maxx);
        return maxx;
    }
};