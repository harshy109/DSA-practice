/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftBoundaries(Node *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left != NULL){
            leftBoundaries(root->left, ans);
        }
        else{
            leftBoundaries(root->right, ans);
        }
        
    }
    
    void leafNodes(Node* root, vector<int> &ans ){
        if(root==NULL) 
            return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }
    
    void rightBoundaries(Node *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right != NULL){
            rightBoundaries(root->right, ans);
        }
        else{
            rightBoundaries(root->left, ans);
        }
        ans.push_back(root->data);
    }
    
    void print(vector<int> v){
        for(int i  = 0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
    vector<int> boundaryTraversal(Node *root) {
        // vector<int> leftBoundary;
        // vector<int> rightBoundary;
        // vector<int> leafNode;
        vector<int> ans;
        //case 1  : root
        ans.push_back(root->data);
        
        leftBoundaries(root->left, ans);
        
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
        rightBoundaries(root->right, ans);
        
        // print(leftBoundary);
        // print(leafNode);
        // print(rightBoundary);
        
        // for(int i = 0; i<leftBoundary.size(); i++){
        //     ans.push_back(leftBoundary[i]);
        // }
        // for(int i = 0; i<leafNode.size(); i++){
        //     if(leafNode[i] != ans.back()){
        //         ans.push_back(leafNode[i]);
        //     }
        // }
        // for(int i = 0; i<rightBoundary.size(); i++){
        //     if((rightBoundary[i] != ans.back()) && (rightBoundary[i] != ans.front())){
        //         ans.push_back(rightBoundary[i]);
        //     }    
        // }
        return ans;
    }
};
