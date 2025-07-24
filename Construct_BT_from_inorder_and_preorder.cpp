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
    int findIndex(vector<int>& inorder,int target){
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex , int inorderStartIndex, int inorderEndIndex, int size){
        //bse case
        if(preOrderIndex >= size){
            return NULL;
        }

        if(inorderStartIndex > inorderEndIndex){
            return NULL;
        }

        int element = preorder[preOrderIndex];
        preOrderIndex++;
        int inorderMidIndex = findIndex(inorder, element);
        TreeNode* root = new TreeNode(element);

        //ab left me chalenge
        //left = inorderStartIndex to inorderMidIndex-1;
        //right = inorderMidIndex+1 to inorderEndIndex;
        root->left = constructTree(preorder, inorder, preOrderIndex, inorderStartIndex, inorderMidIndex-1, size);
        root->right = constructTree(preorder, inorder, preOrderIndex, inorderMidIndex+1, inorderEndIndex, size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preOrderIndex = 0;
        return constructTree(preorder, inorder, preOrderIndex, 0, size-1, size);
    }
};
