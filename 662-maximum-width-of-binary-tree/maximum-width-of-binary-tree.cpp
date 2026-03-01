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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,long long>>q;
        q.push(make_pair(root,1));
        int ans=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            int first=q.front().second;
             int last=first;
            while(n>0){
                TreeNode * temp=q.front().first;
                last=q.front().second;
                long long index=last-first;
                last=index;
                q.pop();
                if(temp->left) q.push(make_pair(temp->left,2*index));
                if(temp->right) q.push(make_pair(temp->right,2*index+1));
                n--;
            }
            ans=max(ans,last+1);  
        }
        return ans;
    }
};