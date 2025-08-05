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
        if(root==NULL){
            return;
        }

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void solve(TreeNode* root, int &k, int &ans){
        if(root == NULL){
            return;
        }

        solve(root->left, k, ans);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        solve(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        //O(n)
        // vector<int> v;
        // inorder(root,v);
        // // 1 2 3 4 5 6 
        // return v[k-1];

        //SC= O(1)
        int ans = 0;
        solve(root, k , ans);
        return ans;
    }
};
