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
    int solve(TreeNode* &root, int& cameras){
        if(root==NULL){
            return 1; //null node ko cover karne ki xrurat nhi hai
        }

        int leftAns = solve(root->left, cameras);
        int rightAns = solve(root->right, cameras);

        if(leftAns == 0 || rightAns == 0){
            cameras++;
            return 2;
        }
        if(leftAns == 2 || rightAns == 2){
            return 1;
        }

        return 0; 
    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int cameras = 0;
        int result = solve(root, cameras);
        if(result == 0){ //agar root node return 1 karti hai
        //matalb ki wo covered nhhi hai to ek camera uspe lga denge
            cameras++;
        }
        return cameras;
    }
};
