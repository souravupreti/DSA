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
    bool help(TreeNode * r1,TreeNode *r2){
        if(!r1&&!r2){
            return true;
        }
        if(r2&&!r1||!r2&&r1){
            return false;
        }
        if(r2->val!=r1->val){
            return false;
        }
        return help(r1->left,r2->right)&&help(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return help(root->left,root->right);
    }
};