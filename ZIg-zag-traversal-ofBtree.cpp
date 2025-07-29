
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
        
        deque<TreeNode*> q;
        q.push_back(root);

        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i<size; i++){
                auto front = q.front();
                q.pop_front();
                if(level%2 != 0){
                    temp[size-i-1] = front->val;
                }
                else{
                    temp[i] = front->val;
                }
                if(front->left){
                    q.push_back(front->left);
                }
                if(front->right){
                    q.push_back(front->right);
                }
            }
            level++;
            ans.push_back(temp);
            temp.clear();


            // if(level%2 == 0){ //even
            //         for(int i = 0; i<size; i++){
            //                 auto front = q.front();
            //                 q.pop_front();
            //                 temp[i] = front->val;
            //                 if(front->left){
            //                     q.push_back(front->left);
            //                 }
            //                 if(front->right){
            //                     q.push_back(front->right);
            //                 }
                            
            //         }
            // }    
            // else{//odd
            //         for(int i =size-1; i>=0; i--){
            //             auto back = q.front();
            //             q.pop_front();
            //             temp[i] = back->val;
            //             if(back->left){
            //                 q.push_back(back->left);
            //             }
            //             if(back->right){
            //                 q.push_back(back->right);
            //             }
            //         }
            // }
      
            //     level++;
            //     ans.push_back(temp);
            //     temp.clear();
 
        }    


            
        return ans;
    }
};
