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
    int findLeftHeight(TreeNode* root){
        int leftHeight = 0;
        while(root!=NULL){
            leftHeight++;
            root = root->left;
        }
        return leftHeight;
    }
    int findRightHeight(TreeNode* root){
        int rightHeight = 0;
        while(root!=NULL){
            rightHeight++;
            root = root->right;
        }
        return rightHeight;
    }
    int countNodes(TreeNode* &root) {
//O(logn * logn)        
        if(root==NULL){
            return 0;
        }
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        if(leftHeight == rightHeight){
            int count = (1<<leftHeight)-1;
            return count;
        }
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }


//O(n)        
        // if(root==NULL){
        //     return 0;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // int count = 0;
        // while(!q.empty()){
        //     TreeNode* front = q.front();
        //     q.pop();

        //     count++;

        //     if(front->left){
        //         q.push(front->left);
        //     }
        //     if(front->right){
        //         q.push(front->right);
        //     }

        // }
        // return count;
    }
};
