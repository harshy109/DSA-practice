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

    void createMap(vector<int>& inorder, unordered_map<int, int> &valIndexMap){
        for(int i = 0; i<inorder.size(); i++){
            int element = inorder[i];
            int index = i;
            valIndexMap[element] = index;
        }
    }
    int findIndex(vector<int>& inorder,int target){
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
        ///this gives overall complexity of O(n2) 
    }
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex , int inorderStartIndex, int inorderEndIndex, int size,  unordered_map<int, int> &valIndexMap){
        //bse case
        if(preOrderIndex >= size){
            return NULL;
        }

        if(inorderStartIndex > inorderEndIndex){
            return NULL;
        }

        int element = preorder[preOrderIndex];
        preOrderIndex++;
        //int inorderMidIndex = findIndex(inorder, element);
        int inorderMidIndex = valIndexMap[element];
        TreeNode* root = new TreeNode(element);

        //ab left me chalenge
        //left = inorderStartIndex to inorderMidIndex-1;
        //right = inorderMidIndex+1 to inorderEndIndex;
        root->left = constructTree(preorder, inorder, preOrderIndex, inorderStartIndex, inorderMidIndex-1, size, valIndexMap);
        root->right = constructTree(preorder, inorder, preOrderIndex, inorderMidIndex+1, inorderEndIndex, size, valIndexMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        createMap(inorder,mp);
        int size = preorder.size();
        int preOrderIndex = 0;
        return constructTree(preorder, inorder, preOrderIndex, 0, size-1, size, mp);
    }
};
