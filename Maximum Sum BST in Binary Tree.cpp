
class Info{
    public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution {
public:
    int minCalc(int a, int b, int c){
        return min(a, min(b,c));
    }
    int maxCalc(int a, int b, int c){
        return max(a, max(b,c));
    }
    Info solve(TreeNode* root, int &sum){
        //base case
        if(root==NULL){
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum, temp.sum);
            return temp;
        }
        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum);

        Info currentAns;

        currentAns.minVal = minCalc(leftAns.minVal, rightAns.minVal, root->val);
        currentAns.maxVal = maxCalc(leftAns.maxVal, rightAns.maxVal, root->val);
        currentAns.sum = leftAns.sum + rightAns.sum + root->val;
        currentAns.isBST = root->val > leftAns.maxVal && rightAns.minVal > root->val && leftAns.isBST && rightAns.isBST;

        if(currentAns.isBST){
            sum = max(currentAns.sum, sum);
        }

        return currentAns;
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        Info ans = solve(root, sum);
        return sum;
    }
};
/*
        checkBST -> > ,<, bst-node
        > minVal of leftSubtree
        < maxVal of rightSubtree
        maxSum
        */
