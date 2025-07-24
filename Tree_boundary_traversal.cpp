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
    void leftBoundaries(Node *root, vector<int> &leftBoundary){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        leftBoundary.push_back(root->data);
        if(root->left != NULL){
            leftBoundaries(root->left, leftBoundary);
        }
        else{
            leftBoundaries(root->right, leftBoundary);
        }
        
    }
    
    void leafNodes(Node* root, vector<int> &leafNode ){
        if(root==NULL) 
            return;
        
        if(root->left == NULL && root->right == NULL){
            leafNode.push_back(root->data);
        }
        leafNodes(root->left, leafNode);
        leafNodes(root->right, leafNode);
    }
    
    void rightBoundaries(Node *root, vector<int> &rightBoundary){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right != NULL){
            rightBoundaries(root->right, rightBoundary);
        }
        else{
            rightBoundaries(root->left, rightBoundary);
        }
        rightBoundary.push_back(root->data);
    }
    
    void print(vector<int> v){
        for(int i  = 0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> leftBoundary;
        vector<int> rightBoundary;
        vector<int> leafNode;
        vector<int> ans;
        
        leftBoundaries(root, leftBoundary);
        leafNodes(root, leafNode);
        rightBoundaries(root, rightBoundary);
        
        // print(leftBoundary);
        // print(leafNode);
        // print(rightBoundary);
        
        for(int i = 0; i<leftBoundary.size(); i++){
            ans.push_back(leftBoundary[i]);
        }
        for(int i = 0; i<leafNode.size(); i++){
            if(leafNode[i] != ans.back()){
                ans.push_back(leafNode[i]);
            }
        }
        for(int i = 0; i<rightBoundary.size(); i++){
            if((rightBoundary[i] != ans.back()) && (rightBoundary[i] != ans.front())){
                ans.push_back(rightBoundary[i]);
            }    
        }
        return ans;
    }
};
