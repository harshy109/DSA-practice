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
    //level order
    void levelOrder(TreeNode* root, vector<int> &v){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            v.push_back(front->val);

            //us data pe operation karo
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    bool searchSumPair(TreeNode* root,TreeNode* node, int k){
        if(node == NULL){
            return false;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if(left && left != node &&  node->val + left->val == k){
            return true;
        }
        else if(right && right != node && node->val + right->val == k){
            return true;
        }
        else{
            bool leftAns = false, rightAns = false;
            if(root->left){
                leftAns = searchSumPair(root->left , node, k) ;
            }
            if(root->right){
                rightAns = searchSumPair(root->right, node, k);
            }
            return leftAns || rightAns ;
        }
    }

    void storeInorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        storeInorder(root->left, v);
        v.push_back(root->val);
        storeInorder(root->right, v);
    }

    bool checkPairSum(vector<int> &v, int k){
        int s = 0;
        int e = v.size() - 1;

        while(s<e){
            int sum = v[s] + v[e];
            if(sum == k){
                return true;
            }
            if(sum < k){
                s++;
            }
            if(sum > k){
                e--;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
//O(n)
        vector<int> v;
        storeInorder(root, v);

        bool ans = checkPairSum(v, k);
        return ans;

//O(n2) 
        // queue<TreeNode*> q;
        // levelOrder(root, q);

        //5 - 3 - 6 - 2 - 4- 7

        // while(!q.empty()){
        //     TreeNode* node = q.front();
        //     q.pop();
        //     bool ans = searchSumPair(root, node, k);
        //     if(ans){
        //         return true;
        //     }
        // }

//O(n2)
        // vector<int> v;
        // levelOrder(root, v);

        // for(int i = 0; i<v.size(); i++){
        //     for(int j = i+1; j<v.size(); j++){
        //         if(v[i] + v[j] == k){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};
