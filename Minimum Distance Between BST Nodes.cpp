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
    void solve(TreeNode* &root, int &ans, TreeNode* &prev){
        if(root == NULL){
            return; 
        }
        solve(root->left, ans, prev);
        //solve krna hai
        if(prev!=NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        solve(root->right, ans, prev);
    }
public:
    void insertA(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        insertA(root->left, v);
        v.push_back(root->val);
        insertA(root->right, v);
    }
    // void solve(TreeNode* root, int &minDiff, int &rval){
    //     if(root == NULL){
    //         return;
    //     }
    //     solve(root->left,minDiff, rval);
    //     if(root->val < rval){
    //         minDiff = root->val;
    //     }
    //     solve(root->right, minDiff,rval);
    // }
    // int checkForEachNode(TreeNode* root, int &minDiff){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     checkForEachNode( root->left, minDiff);
    //     solve(root, minDiff, root->val);
    //     checkForEachNode( root->right, minDiff);
    //     return minDiff;
    // }
    
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        solve(root,ans, prev);
        return ans;


        // if(root== NULL){
        //     return 0;
        // }
        // int minDiff = INT_MAX;
        // return checkForEachNode(root, minDiff);
        // return minDiff;

        //O(n2)
        // vector<int> v;
        // insertA(root, v);

        // int minDiff = INT_MAX;
        // int minSum = INT_MAX;
        // for(int i = 0; i<v.size()-1; i = i+2){
        //     if(abs(v[i] - v[i+1]) <minDiff){
        //         minDiff = abs(v[i] - v[i+1]);
        //     }
        // }
        // return minDiff;
        // for(int i = 0; i< v.size() ;i ++){
        //     for(int j = i+1; j<v.size(); j++){
        //         if(abs(v[i] - v[j]) < minSum){
        //             minSum = abs(v[i] - v[j]);
        //         }
        //     }
        // }
        //return minSum;
    }
};
