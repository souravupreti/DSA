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
    // TreeNode * create(int a,TreeNode * root){
    //    if(!root){
    //     TreeNode * temp=new TreeNode (a);
    //     return temp;
    //    }
    //    if(root->val>a){
    //     root->left=create(a,root->left);
    //    }
    //    else{
    //     root->right=create(a,root->right);
    //    }
    //    return root;
    // }


    TreeNode * create(vector<int>& preorder,int bound,int &i){
        if(i==preorder.size()||preorder[i]>bound){
            return NULL;
        }
            TreeNode * temp=new TreeNode (preorder[i++]);
            temp->left=create(preorder,temp->val,i);
            temp->right=create(preorder,bound,i);
            return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return create(preorder,INT_MAX,i);
    }
};