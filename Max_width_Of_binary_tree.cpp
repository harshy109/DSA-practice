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
    int widthOfBinaryTree(TreeNode* root) {
        //level order lagega
        int maxWidth = INT_MIN;
        if(root == NULL){
            return maxWidth;
        }
        queue<pair<TreeNode*, int>> q;
        int index = 0;
        
        q.push(make_pair(root, index++));
        int rightMostIndex = 0;
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front = q.front().first;
            if(front!=NULL){
                int leftMostIndex = q.front().second;
            }
            q.pop();

            if(front == NULL){
                int thisLevelWidth = rightMostIndex - leftMostIndex + 1;
                maxWidth = max(maxWidth, thisLevelWidth);
                // q.pop();
                rightMostIndex = q.front().second;

                if(!q.empty()){
                    q.push(make_pair(NULL,NULL));
                }
            }
            else{

                if(front->left) {
                    q.push(make_pair(front->left, index++));
                }
                else{
                    q.push(make_pair(NULL, index++));
                }
                if(front->right){
                    q.push(make_pair(front->right, index++));
                }
                else{
                    q.push(make_pair(NULL, index++));
                }
            }
        }
        return ans;
    }
};
