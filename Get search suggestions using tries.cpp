#include<iostream>
#include<unordered_map>
#include<vector>
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

void storeString(TrieNode* root, vector<string>& ans, string output){
    //conditon 
    if(root->isTerminal){
        ans.push_back(output);
    }

    for(auto it : root->children){
        char ch = it.first;
        TrieNode* child = it.second;
        output.push_back(ch);
        storeString(child, ans, output);
        output.pop_back();
    }
}

void findWordsWithPrefix(TrieNode* root, vector<string>& ans, string prefix){
    //base case
    if(prefix.length() == 0){
        string output="";
        storeString( root, ans, output);
    }

    char ch = prefix[0];
    TrieNode* child;

    if(root->children.count(ch) == 1){
        child = root->children[ch];
    }
    else{
        return;
    }

    findWordsWithPrefix(child , ans, prefix.substr(1));
}

vector<vector<string>> getSuggestions(TrieNode* root, string prefix){
    vector<vector<string>> ans;
    string temp = "";
    for(int i = 0; i<prefix.length(); i++){
        temp.push_back(prefix[i]);
        vector<string> tempAns;
        findWordsWithPrefix(root, tempAns, temp);
        for(int j = 0; j<tempAns.size(); j++){
            tempAns[j] = temp+tempAns[j] ;
        }
        ans.push_back(tempAns);
    }
    return ans;
}


int main()
{
    TrieNode* root = new TrieNode('-');
    insertIntoTrie(root, "baba");
    insertIntoTrie(root, "babbar");
    insertIntoTrie(root, "baby");
    insertIntoTrie(root, "bala");
    cout<<"Insertion done"<<endl;

    //usign one prefix - bab
    // vector<string> ans;
    // string prefix = "bab";
    // findWordsWithPrefix(root, ans, prefix);

    // for(auto it : ans){
    //     cout<<prefix + it<<endl;
    // }

    //using sub-sequences of prefix - bab : b, ba, bab
    string prefix = "bab";
    vector<vector<string>> ans = getSuggestions(root, prefix);
    for(auto itr : ans){
        for(auto it : itr){
            cout<<it<<", ";
        }
        cout<<endl;
    }
 



    return 0;
}
