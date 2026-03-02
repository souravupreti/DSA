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
    void parenti(unordered_map<TreeNode *,TreeNode *>&parent,TreeNode *root){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *>parent;
        parenti(parent,root);
        unordered_map<TreeNode *,bool>visit;
        queue<TreeNode *>q;
        q.push(target);
        visit[target]=true;
        int count=0;
        while(!q.empty()){
            int n=q.size();
            if(count++==k) break;
            while(n>0){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left&&!visit[temp->left]){
                    q.push(temp->left);
                    visit[temp->left]=true;
                }
                if(temp->right&&!visit[temp->right]){
                    q.push(temp->right);
                    visit[temp->right]=true;
                }
                if(parent[temp]&&!visit[parent[temp]]){
                    q.push(parent[temp]);
                    visit[parent[temp]]=true;
                }
                n--;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};