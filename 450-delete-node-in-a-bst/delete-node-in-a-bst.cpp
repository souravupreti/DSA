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
            return NULL;
        }
        if(root->val>key){
           root->left=deleteNode (root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }
            if(root->left&&!root->right){
                TreeNode * temp=root->left;
                delete root;
                return temp;
            }
            if(root->right&&!root->left){
                TreeNode * temp=root->right;
                delete root;
                return temp;
            }
            else{
                TreeNode * parent=root;
                TreeNode * child=root->left;
                while(child->right){
                    parent=child;
                    child=child->right;
                }
                if(root==parent){
                    child->right=root->right;
                    delete root;
                    return child;
                }
                else{
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
           
        }
        return root;
    }
};