#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    //constructor 
    TrieNode(char data){
        value = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //ek case me solve karungi baki recursion
    char ch = word[0];
    TrieNode* child;

    //do case hai
    //present hai to search krke laga do
    if(root->children.count(ch) == 1){
        child = root->children[ch];
    }
    //absent hai to create kardo
    else{
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    //baki recursion sambhal lega
    insertIntoTrie(child, word.substr(1));  
}

bool searchTrie(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    //ek case
    char ch = word[0];
    TrieNode* child;
    
    if(root->children.find(ch) != root->children.end()){
        child = root->children[ch];
    }
    else{
        return false;
    }

    bool recursionKaAns = searchTrie(child, word.substr(1));
    return recursionKaAns;
}

void deleteTrie(TrieNode* root, string word){
    //base case aaega
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    //ek case hum solve krenge
    char ch = word[0];
    TrieNode* child; 
    //search karenge
    //present hai to jaenge
    if(root->children.count(ch) == 1){
        child = root->children[ch];
    }
    else{
        return;
    }
    
    return deleteTrie(child, word.substr(1));
    
}


int main()
{
    TrieNode* root = new TrieNode('-');
    insertIntoTrie(root, "count");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "coverage");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "tail");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "ego");
    insertIntoTrie(root, "pal");
    cout<<"Insertion done"<<endl;

    bool ans = searchTrie(root, "cover");
    if(ans){
        cout<<"Found "<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

    deleteTrie(root, "cover");
    
    ans = searchTrie(root, "cover");
    if(ans){
        cout<<"Found "<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}
