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
void inorder(TreeNode * root,vector<int>&r){
        if(!root){
            return ;
        }
        inorder(root->left,r);
        r.push_back(root->val);
        inorder(root->right,r);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        int l=0;
        int h=v.size()-1;
        while(l<h){
            if(v[l]+v[h]==k){
                return true;
            }
            else if(v[l]+v[h]>k){
                h--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};