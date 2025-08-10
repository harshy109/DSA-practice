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
    void insertA(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        insertA(root->left, v);
        v.push_back(root->val);
        insertA(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        insertA(root, v);

        int minSum = INT_MAX;
        for(int i = 0; i< v.size() ;i ++){
            for(int j = i+1; j<v.size(); j++){
                if(abs(v[i] - v[j]) < minSum){
                    minSum = abs(v[i] - v[j]);
                }
            }
        }
        return minSum;
    }
};
