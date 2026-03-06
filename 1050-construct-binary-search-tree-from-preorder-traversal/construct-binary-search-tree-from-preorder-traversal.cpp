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
    TreeNode * create(int a,TreeNode * root){
       if(!root){
        TreeNode * temp=new TreeNode (a);
        return temp;
       }
       if(root->val>a){
        root->left=create(a,root->left);
       }
       else{
        root->right=create(a,root->right);
       }
       return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=nullptr;
         for(int i=0;i<preorder.size();i++){
           root= create(preorder[i],root);
        }
        return root;
    }
};