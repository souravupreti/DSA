class box{
public:
    int bst;
    int min;
    int max;
    int size;

    box(int data){
        bst = 1;
        size = data;
        min = data;
        max = data;
    }
};

class Solution {
public:

box* find(TreeNode *root, int &ans){

        if(!root) return NULL;

        // leaf node
        if(!root->left && !root->right){
            ans = max(ans, root->val);
            return new box(root->val);
        }

        // only right child
        else if(!root->left && root->right){

            box *temp = find(root->right, ans);

            if(temp && temp->bst && temp->min > root->val){
                temp->size += root->val;
                temp->min = root->val;
                ans = max(ans, temp->size);
                return temp;
            }
            else{
                if(temp) temp->bst = 0;
                return temp;
            }
        }

        // only left child
        else if(root->left && !root->right){

            box *temp = find(root->left, ans);

            if(temp && temp->bst && temp->max < root->val){
                temp->size += root->val;
                temp->max = root->val;
                ans = max(ans, temp->size);
                return temp;
            }
            else{
                if(temp) temp->bst = 0;
                return temp;
            }
        }

        // both children
        else{

            box *temp1 = find(root->left, ans);
            box *temp2 = find(root->right, ans);

            if(temp1 && temp2 &&
               temp1->bst && temp2->bst &&
               temp1->max < root->val &&
               temp2->min > root->val){

                box *temp = new box(root->val);

                temp->size = temp1->size + temp2->size + root->val;
                temp->min = temp1->min;
                temp->max = temp2->max;

                ans = max(ans, temp->size);

                return temp;
            }
            else{
                if(temp1) temp1->bst = 0;
                return temp1;
            }
        }
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        find(root, ans);
        return ans;
    }
};