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
class Info{
    public:
    int minVal;
    int maxVal;
    bool isBST;
};
class Solution {
public:
    Info solve(TreeNode* root){
        if(root==NULL){
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.isBST = true;
            return temp;
        }
        Info leftAns = solve(root->left);
        Info rightAns = solve(root->right);

        Info current;
        current.minVal = min(root->val, min(leftAns.minVal, rightAns.minVal) );
        current.maxVal = max(root->val,max( leftAns.maxVal, rightAns.maxVal) );
        current.isBST = leftAns.isBST && rightAns.isBST && root->val > leftAns.maxVal && root->val < rightAns.minVal;
        return current; 
    }
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        // Info myAns = solve(root);
        // return myAns.isBST;
        vector<int> v;
        inorder(root, v);
        for(int i = 0; i<v.size()-1; i++){
            if(v[i+1] <= v[i]){
                return false;
            }
        }
        return true;
    }
};
