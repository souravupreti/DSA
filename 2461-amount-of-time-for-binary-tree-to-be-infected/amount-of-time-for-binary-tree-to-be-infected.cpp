class Solution {
public:

    void find(TreeNode* root, int target, TreeNode*& node) {
        if (!root) return;

        if (root->val == target) {
            node = root;
            return;
        }

        find(root->left, target, node);
        find(root->right, target, node);
    }

    void parenti(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {

        TreeNode* target = NULL;
        find(root, start, target);

        unordered_map<TreeNode*, TreeNode*> parent;
        parenti(parent, root);

        unordered_map<TreeNode*, bool> visit;
        queue<TreeNode*> q;

        q.push(target);
        visit[target] = true;

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;

            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && !visit[temp->left]) {
                    q.push(temp->left);
                    visit[temp->left] = true;
                }

                if (temp->right && !visit[temp->right]) {
                    q.push(temp->right);
                    visit[temp->right] = true;
                }

                if (parent.count(temp) && !visit[parent[temp]]) {
                    q.push(parent[temp]);
                    visit[parent[temp]] = true;
                }
            }
        }

        return minutes;
    }
};