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
class Info{
    public:
    long long minVal;
    long long maxVal;
    bool isBST;
};
class Solution {
public:
        long long minCalculate(long long a, long long b, long long c){
            return min(a, min(b,c));
        }
        long long maxCalculate(long long a, long long b, long long c){
            return max(a, max(b,c));
        }
    //1
    Info solve(TreeNode* root){
        if(root==NULL){
            Info temp;
            temp.minVal = LONG_MAX;
            temp.maxVal = LONG_MIN;
            temp.isBST = true;
            return temp;
        }
        Info leftAns = solve(root->left);
        Info rightAns = solve(root->right);

        Info current;
        current.minVal = minCalculate(root->val, leftAns.minVal, rightAns.minVal);
        current.maxVal = maxCalculate(root->val, leftAns.maxVal, rightAns.maxVal);
        current.isBST = leftAns.isBST && rightAns.isBST && root->val > leftAns.maxVal && root->val < rightAns.minVal;
        return current; 
    }
    //2
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    //3
    bool validate(TreeNode* root,long long lb, long long ub){
        if(root== NULL){
            return true;
        }
        //preorder
        bool isCurrBST = root->val > lb && root->val < ub;

        bool isLeftBST = validate(root->left, lb, root->val);
        bool isRightBST = validate(root->right, root->val , ub);

        return isCurrBST && isLeftBST && isRightBST;
    }
    bool isValidBST(TreeNode* root) {
        //1
        Info myAns = solve(root);
        return myAns.isBST;
        //2
        // vector<int> v;
        // inorder(root, v);
        // for(int i = 0; i<v.size()-1; i++){
        //     if(v[i+1] <= v[i]){
        //         return false;
        //     }
        // }
        // return true;
        //3
        // long long lb = LONG_MIN;
        // long long ub = LONG_MAX;

        // return validate(root, lb, ub);
    }
};
