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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);   
    }

    void convert(TreeNode* &root, vector<int> &v){
        if(root == NULL){
            return;
        }

        //L N R - > R N L
        convert(root->right, v);

        root->val = v.back();
        v.pop_back();

        convert(root->left, v);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int n = v.size() - 1;
        //0 - 1 - 2 - 3 - 4 - 5- 6 - 7 - 8
        for(int i = n-1; i >= 0; i--){
            v[i] += v[i+1];
        }

        convert(root, v);
        return root;
    }
};
