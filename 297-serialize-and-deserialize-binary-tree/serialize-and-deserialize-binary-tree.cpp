class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "#";

        queue<TreeNode*> q;
        q.push(root);
        string ans = "";

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                ans += "#|";
                continue;
            }

            ans += to_string(temp->val) + "|";
            q.push(temp->left);
            q.push(temp->right);
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;

        int i = 0;
        string curr = "";

        // read root
        while(data[i] != '|'){
            curr += data[i];
            i++;
        }
        TreeNode* root = new TreeNode(stoi(curr));
        queue<TreeNode*> q;
        q.push(root);
        i++; // skip '|'

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            // LEFT
            curr = "";
            while(i < data.size() && data[i] != '|'){
                curr += data[i];
                i++;
            }
            i++;

            if(curr != "#"){
                temp->left = new TreeNode(stoi(curr));
                q.push(temp->left);
            }

            // RIGHT
            curr = "";
            while(i < data.size() && data[i] != '|'){
                curr += data[i];
                i++;
            }
            i++;

            if(curr != "#"){
                temp->right = new TreeNode(stoi(curr));
                q.push(temp->right);
            }
        }

        return root;
    }
};