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
void it(TreeNode *root1,vector<int>&v1){
      if(!root1){
          return ;
      }
      it(root1->left,v1);
      v1.push_back(root1->val);
      it(root1->right,v1);
      
  }
  bool check(vector<int>v,int target){
    int i=0;int j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==target){
            return true;
        }
        else if(v[i]+v[j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
  }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inn;
        it(root,inn);
        return check(inn,k);
    }
};