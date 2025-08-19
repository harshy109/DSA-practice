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
    int binarySearch(vector<int> & arr, int s, int e, int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(target < arr[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &preorderIndex, int s, int e){
        if(s>e){
            return NULL;
        }
        if(preorderIndex >= preorder.size()){
            return NULL;
        }
        int element = preorder[preorderIndex];
        TreeNode* root = new TreeNode(element);
        preorderIndex++;
        int inorderIndex = binarySearch(inorder, s, e, element);

        root->left = solve(inorder, preorder, preorderIndex, s, inorderIndex-1);
        root->right = solve(inorder, preorder, preorderIndex, inorderIndex+1, e);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        int preorderIndex = 0;
        int s = 0;
        int e = preorder.size()-1;
        TreeNode* root = solve(inorder, preorder, preorderIndex, s, e);
        return root;
    }
};
