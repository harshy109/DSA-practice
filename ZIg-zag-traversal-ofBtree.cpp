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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL ){
                ans.push_back(temp);
                temp.clear();
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
            }
            else{
                temp.push_back(front->val);
                if(level%2 != 0){
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
                else{
                    if(front->right){
                        q.push(front->right);
                    }
                    if(front->left){
                        q.push(front->left);
                    }
                }
            }
           
        }
        return ans;
    }
};
