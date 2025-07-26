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
    void solve(TreeNode* root, int &targetSum, int sum, vector<vector<int>> &ans, vector<int> temp){
        if(root == NULL) return ;

        sum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            else{
                return;
            }
        }

        solve(root->left, targetSum,sum, ans, temp);
        solve(root->right, targetSum,sum, ans, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum,0, ans, temp);
        return ans;
    }
};


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
    bool checkSum(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return false;
        }
        sum+=root->val;
        if(root->left == NULL  && root->right == NULL){
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        bool left = checkSum(root->left, targetSum, sum);
        bool right = checkSum(root->right, targetSum, sum);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = checkSum(root, targetSum , sum);
        return ans;
    }
};
