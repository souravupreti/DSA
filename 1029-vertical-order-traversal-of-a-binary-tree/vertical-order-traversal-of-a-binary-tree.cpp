class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});  // node, {column, row}

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {col-1, row+1}});

            if(node->right)
                q.push({node->right, {col+1, row+1}});
        }

        vector<vector<int>> ans;

        for(auto &c : nodes) {
            vector<int> temp;
            for(auto &r : c.second) {
                temp.insert(temp.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};