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
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftSubtree = getHeight(root->left);
        int rightSubtree =getHeight(root->right);
        int maxHeight = max(leftSubtree , rightSubtree);
        int totalHeight = maxHeight+1;
        return totalHeight; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0;
        }

        //we have three options - 
        //leftSUbtree
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getHeight(root->left) + getHeight(root->right);
        int maxDiameter = max(option1, max(option2, option3));
        return maxDiameter;
        //rightsubtree
        //combination
    }
};
