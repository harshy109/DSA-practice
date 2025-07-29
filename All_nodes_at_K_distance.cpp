/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createMapping(TreeNode* root, unordered_map<TreeNode* ,TreeNode*> &parentMap){
        if(!root) return;
        if(root->left){
            parentMap[root->left] = root;
            createMapping(root->left, parentMap);
        }
        if(root->right){
            parentMap[root->right] =root;
            createMapping(root->right, parentMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parentMap;
        parentMap[root] = NULL;
        createMapping(root, parentMap);

        unordered_map<TreeNode* ,bool> visited;
        queue<TreeNode*> q;
        //start humne target se hi karna hai , level wise
        q.push(target); 
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel == k){
                break;
            }
            currLevel++;
            for(int i= 0; i<size; i++){
                auto front = q.front();
                q.pop();
                if(front->left && visited.find(front->left)== visited.end()){
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && visited.find(front->right) == visited.end()){
                    q.push(front->right);
                    visited[front->right] = true;
                }
                TreeNode* parentNode = parentMap[front];
                if(parentNode && visited.find(parentNode) == visited.end()){
                    q.push(parentNode);
                    visited[parentNode] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            ans.push_back(node->val);
            q.pop();
        }
        return ans;
    }
};
