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
    void preorder(TreeNode* &root, queue<TreeNode*> &q){
        if(root==NULL){
            return;
        }

        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }
    void insertIntoLL(TreeNode* &root, queue<TreeNode*> &q){
        if(q.empty()){
            return;
        }
        root = q.front();
        q.pop();
        root->left = NULL;
        insertIntoLL(root->right, q);
    
    }
    void flatten(TreeNode* root) {
        //preordertraversal
        queue<TreeNode*> q;
        preorder(root, q);

        insertIntoLL(root, q);
    }
};
