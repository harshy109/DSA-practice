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
    //level order
    void levelOrder(TreeNode* root, vector<int> &v){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            v.push_back(front->val);

            //us data pe operation karo
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    bool searchSumPair(TreeNode* root,TreeNode* node, int k){
        if(node == NULL){
            return false;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if(left && left != node &&  node->val + left->val == k){
            return true;
        }
        else if(right && right != node && node->val + right->val == k){
            return true;
        }
        else{
            bool leftAns = false, rightAns = false;
            if(root->left){
                leftAns = searchSumPair(root->left , node, k) ;
            }
            if(root->right){
                rightAns = searchSumPair(root->right, node, k);
            }
            return leftAns || rightAns ;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        // queue<TreeNode*> q;
        // levelOrder(root, q);

        //5 - 3 - 6 - 2 - 4- 7

        // while(!q.empty()){
        //     TreeNode* node = q.front();
        //     q.pop();
        //     bool ans = searchSumPair(root, node, k);
        //     if(ans){
        //         return true;
        //     }
        // }

        vector<int> v;
        levelOrder(root, v);

        for(int i = 0; i<v.size(); i++){
            for(int j = i+1; j<v.size(); j++){
                if(v[i] + v[j] == k){
                    return true;
                }
            }
        }
        return false;
    }
};
