/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    //     if (root == NULL) return false;

    //     path.push_back(root);

    //     if (root == target) return true;

    //     if (findPath(root->left, target, path) || 
    //         findPath(root->right, target, path))
    //         return true;

    //     path.pop_back();   
    //     return false;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode *>a;
        // vector<TreeNode *>b;
        // findPath(root,p,a);
        // findPath(root,q,b);
        // TreeNode* ans;
        // int i=0,j=0;
        // while(i<a.size()&&j<b.size()){
        //     if(a[i] == b[i]){
        //         ans=a[i];
        //     }
        //     i++;j++;
        // }
        // return ans;


        if(root==NULL||root==p||root==q){
            return root;
        }
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);
        if(!left){
            return right;
        }
        else if(!right){
            return left;
        }
        else{
            return root;
        }


    }
};