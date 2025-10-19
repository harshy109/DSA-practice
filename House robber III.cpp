
class Solution {
public:
    int solve(TreeNode* root){
        //base case
        if(root == NULL){
            return 0;
        }

        int robThisHouse = 0;
        int dontRobThisHouse = 0;

        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            robThisHouse += solve(root->right->left) + solve(root->right->right);
        }

        dontRobThisHouse += solve(root->left) + solve(root->right);

        return max(robThisHouse, dontRobThisHouse);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};
