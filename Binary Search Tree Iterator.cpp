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
class BSTIterator {
public:
    vector<int> v;
    int i = 0;
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL )return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    BSTIterator(TreeNode* root) {
        
    }
    
    int next() {
        inorder(root,v);
        if(i<v.size()){
            int num = v[i];
            i++;
            return num;
        }
        return 0;
    }
    
    bool hasNext() {
        return !v.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */Binary Search Tree Iterator
