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
    //first approach - paassed 24 test cases
    void preOrder(TreeNode* &root, int row, int col, unordered_map<int, vector<int>> &colMap){
        if(root == NULL){
            return;
        }

        colMap[col].push_back(root->val);

        preOrder(root->left, row+1, col-1, colMap);
        preOrder(root->right, row+1, col+1, colMap);
    }
    //second approach  - submitted
    void preOrderWithMap(TreeNode* &root, int row, int col, map<int,map<pair<int,int>,vector<int>>> &colMap ){
        if(root == NULL){
            return;
        }

        colMap[col][{row, col}].push_back(root->val);
    
        preOrderWithMap(root->left, row+1, col-1, colMap);
        preOrderWithMap(root->right, row+1, col+1, colMap);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<pair<int,int>, vector<int>>> colMap;
        vector<vector<int>> ans;

        preOrderWithMap(root, 0, 0, colMap);
    
        for(auto itr : colMap ){
            map<pair<int,int>, vector<int>> mp(itr.second);
            vector<int> temp;
            for(auto iitr : mp){
                sort(iitr.second.begin(), iitr.second.end());
                for(auto itrIn : iitr.second){
                    temp.push_back(itrIn);
                }
            }
            ans.push_back(temp);
        }

        return ans;

        // vector<vector<int>> ans;
        // unordered_map<int, vector<int>> colMap;

        // preOrder(root, 0, 0, colMap);
        // int minIndexofMap = INT_MAX;
        // int maxIndexofMap = INT_MIN;
        // for(auto it : colMap){
        //     minIndexofMap = min(minIndexofMap, it.first);
        //     maxIndexofMap = max(maxIndexofMap, it.first);
        // }
        // for(int i = minIndexofMap; i<=maxIndexofMap; i++){
        //     vector<int> temp = colMap[i];
        //     sort(temp.begin(), temp.end());
        //     ans.push_back(temp);
        // }
        // return ans;
    }
};
