class Solution {
public:
    int findMax(TreeNode* root){
        if(root->right ==NULL){
            return root->val;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == key){
            //4 cases 
            //leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            //left child only
            if(root->left != NULL && root->right == NULL){
                TreeNode* leftChild = root->left;
                root->left = NULL;
                return leftChild;
            }
            //right child only
            if(root->left == NULL && root->right != NULL){
                TreeNode* rightChild = root->right;
                root->right = NULL;
                return rightChild;
            }
            //both left and right child
            if(root->left != NULL && root->right != NULL){
                //find maxVal in left subtree
                int maxVal = findMax(root->left);
                //replace root nodes value with maxVal
                root->val = maxVal;
                //actual tree me maxVal wali node dhundh ke deletw kardo
                root->left = deleteNode(root->left, maxVal);
                return root;
            }
        }
        else{
            if(key < root->val){
                root->left = deleteNode(root->left, key);
            }
            else if(key > root->val){
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};
