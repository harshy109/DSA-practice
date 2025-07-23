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
    int getHeight(TreeNode* &root){
        if(root == NULL){
            return 0;
        }

        int leftSubtreeHeight = getHeight(root->left);
        int rightSubtreeHeight = getHeight(root->right);
        int maxHeight = max(leftSubtreeHeight, rightSubtreeHeight);
        return maxHeight+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool status;
        int leftSubtreeHeight = getHeight(root->left);
        int rightSubtreeHeight = getHeight(root->right);
        if(abs(leftSubtreeHeight - rightSubtreeHeight) <=1){
            status = true;
        }
        else status = false;

        bool lh = isBalanced(root->left);
        bool rh = isBalanced(root->right);

        if(status && lh && rh) return true;
        else return false;
    }
};
