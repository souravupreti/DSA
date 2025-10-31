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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            //0 children 
            if(!root->right&&!root->left){
                delete root;
                return nullptr;
            }
             //1 children 
             if(!root->left){
                TreeNode *temp=root->right;
                delete root;
                return temp;
             }
             if(!root->right){
                TreeNode *temp=root->left;
                delete root;
                return temp;
             }
             //2 children 
             TreeNode* child=root->left;
             TreeNode* parent=root;
             while(child->right){
                parent=child;
                child=child->right;
                
             }
             if(parent!=root){
                parent->right=child->left;
                child->left=root->left;
                child->right=root->right;
                delete root;
                return child;
             }
             else{
                child->right=root->right;
                delete root;
                return child;
             }
             
        }
        return root;
    }
};