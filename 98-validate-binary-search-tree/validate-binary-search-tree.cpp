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

    int check(TreeNode* root,long long & pre){
        if(!root){
            return 1;
        }
        int l=check(root->left,pre);
        if(l==0){
            return 0;
        }
        if(pre>=root->val)
        {
            return 0;
        }
        pre=root->val;
        return check(root->right,pre);
        
    }
    bool isValidBST(TreeNode* root) {
           long long pre = LLONG_MIN; // Use long long to avoid INT_MIN edge case
        return check(root, pre);
    }
};