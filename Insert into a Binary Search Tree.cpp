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
    void solve(TreeNode* &root, int val){
        if(root == NULL){
            return;
        }
        if(val < root->val){
            if(root->left){
                solve(root->left, val);
            }
            else{
                root->left = new TreeNode(val);
                return;
            }
        }
        else{
            if(root->right){
                solve(root->right, val);
            }
            else{
                root->right = new TreeNode(val);
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
        }
        else{
            solve(root, val);
        }
        return root;
    }
};
