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
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &valIndexMap, int &postIndex,int inStart,int inEnd){
        if(postIndex< 0){
            return NULL;
        }
        if(inStart > inEnd){
            return NULL;
        }
        
        int element = postorder[postIndex];
        TreeNode* root = new TreeNode(element);
        int elementFoundAtIndex = valIndexMap[element];
        postIndex--;
       
        root->right = createTree(inorder, postorder,valIndexMap, postIndex, elementFoundAtIndex+1, inEnd);
        root->left = createTree(inorder, postorder,valIndexMap, postIndex, inStart, elementFoundAtIndex-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int postIndex = postorder.size()-1;
        int inStart = 0;
        int inEnd = postorder.size()-1;
        unordered_map<int, int> valIndexMap;
        createMap(inorder, valIndexMap);
        return  createTree(inorder, postorder,valIndexMap, postIndex, inStart, inEnd);
    }
};
