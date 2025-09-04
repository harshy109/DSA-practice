class Trie{
    public:
    char data;
    unordered_map<char, Trie*> children;
    bool isTerminal;

    Trie(char val){
        data = val;
        isTerminal = false;
    }
};

void insertTrie(Trie* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //ekl case hum solve krenge
    char ch = word[0];
    Trie* child;
    //agar present hai to whaha tak chel jao
    if(root->children.count(ch) == 1){
        child = root->children[ch];
    }
    else{
        child = new Trie(ch);
        root->children[ch] = child;
    }
    insertTrie(child, word.substr(1));
}

class Solution {
public:
    void findlcp(Trie* &root, string &ans){
        //base case
        if(root->isTerminal == true){
            return;
        }


        Trie* child;

        //ek case hum solve krenge
        if(root->children.size() == 1){
            for(auto it : root->children){
                char ch = it.first;
                ans.push_back(ch);
                child = root->children[ch];
            }
            
        }
        else{
            return;
        }
        findlcp(child, ans);
    }
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie('-');
        
        for(auto str : strs){
            insertTrie(root, str);
        }

        string ans = "";
        findlcp(root, ans);
        return ans;


        // string ans;
        // int i=0; 
        // while(true){
        //     char curr_char = 0;
        //     for(auto str : strs){
        //         if(i >= str.size()){
        //             curr_char=0;
        //             break;
        //         }
        //         if(curr_char == 0){
        //             curr_char = str[i];
        //         }
        //         else if(curr_char != str[i]){
        //             curr_char = 0;
        //             break;
        //         }
        //     }
        //     if(curr_char == 0 ){
        //         break;
        //     }
        //     ans.push_back(curr_char);
        //     i++;
        // }
        // return ans;
    }
};
