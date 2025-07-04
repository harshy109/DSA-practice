class Solution {
public:
    void appendCopy(string &word){
        word = word+word;
    }
    void changeAppend(string &word){
                    string newStr = "";
                    for(int i = 0; i<word.length(); i++){
                        char ch = word[i];
                        newStr+=(ch+1);
                    }
                    word = word + newStr;
    }
    char kthCharacter(long long k, vector<int>& op) {
        string word = "a";

        for(int i = 0; i<op.size(); i++){
            if(op[i]==1){
                changeAppend(word);
            }
            else if(op[i]==0){
                word += word;
            }
        }

        return word[k-1];
    }
};
