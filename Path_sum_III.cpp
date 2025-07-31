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
    void solve(TreeNode* &root, int &targetSum, int sum, vector<vector<int>> &ans, vector<int> &temp){
        if(root == NULL) return;

        int value = abs(root->val);
        if(((sum + value) <= targetSum)){
            sum += value;
            temp.push_back(value);
        }
        if(sum == targetSum){
            ans.push_back(temp);
            // temp.pop_back();
            return;solve(root->left, targetSum, sum, ans, temp);
        solve(root->right, targetSum, sum, ans, temp);
        }
        
        solve(root->left, targetSum, sum, ans, temp);
        solve(root->right, targetSum, sum, ans, temp);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        if(targetSum == 0) return 0;
        int k = abs(targetSum);
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, k,sum, ans, temp);
        if(ans.empty()){
            return 0;
        }
        return ans.size();
    }
};
