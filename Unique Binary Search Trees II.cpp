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
    vector<TreeNode*> solve(int start, int end){
        //base case
        if(start > end){
            return {0};
        }

        vector<TreeNode*> ans;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> left = solve(start, i-1);
            vector<TreeNode*> right = solve(i+1, end);
            for(int j = 0; j<left.size(); j++){
                for(int k = 0; k<right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    //vector<vector<vector<TreeNode*>>> dp(n+1, vector<TreeNode*>(n+1, vector<)); 
    map<pair<int, int>, vector<TreeNode*>> dp;
    vector<TreeNode*> solveMem(int start, int end){
        //base case
        if(start > end){
            return {0};
        }
        if(dp.find({start, end}) != dp.end()){
            return dp[{start, end}];
        }

        vector<TreeNode*> ans;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> left = solve(start, i-1);
            vector<TreeNode*> right = solve(i+1, end);
            for(int j = 0; j<left.size(); j++){
                for(int k = 0; k<right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        //return solve(1,n);

        //TD
       
        return solveMem(1,n);
    
    }
};
