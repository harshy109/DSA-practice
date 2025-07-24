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
    bool findSum(TreeNode* root, int &targetSum, int sum){
        
        if(sum > targetSum){
            return false;
        }
        else if(sum == targetSum){
            return true;
        }
        else if(root == NULL){
            return false;
        }
        

        sum += root->val;
        //bool currNode = root->val == targetSum ? true : false;
        bool leftAns = findSum(root->left, targetSum, sum);
        bool rightAns = findSum(root->right, targetSum, sum);

        return  leftAns ||  rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        if(targetSum = 0 && root->val!=0) return false;

        return findSum(root, targetSum, 0);
    }
};
