
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
    void findMaxHeight(TreeNode* &root, int &maxDep, int depth){
        if(root == NULL){
            maxDep = max(depth, maxDep);
            return;
        }

        findMaxHeight(root->left, maxDep, depth+1);
        findMaxHeight(root->right, maxDep, depth+1);
    }
    int maxDepth(TreeNode* root) {
        int maxDep = INT_MIN;
        int depth = 0;
        findMaxHeight(root,maxDep,depth);
        return maxDep;
        
        // if(root == NULL){
        //     return 0;
        // }

        // int leftSubtree = maxDepth(root->left);
        // int rightSubtree = maxDepth(root->right);

        // int maxHeight = max(leftSubtree, rightSubtree);

        // return maxHeight+1;
    }
};
