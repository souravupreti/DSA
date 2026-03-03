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
TreeNode * create(int &i,int start,int end,vector<int>& preorder, vector<int>& inorder){
        if(i<0){
            return NULL;
        }
        if(start>end){
            return NULL;
        }
        TreeNode * root=new TreeNode(preorder[i]); //node 
        int j;
        for(j=start;j<=end;j++){     //1 index j=1
            if(inorder[j]==preorder[i]){
                break;
            }
        }
        i--;
        //start=0   j=0
        root->right=create(i,j+1,end,preorder,inorder);
         root->left=create(i,start,j-1,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int i=postorder.size()-1;
        return create(i,0,postorder.size()-1,postorder,inorder);
    }
};