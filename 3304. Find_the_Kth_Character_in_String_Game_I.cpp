//Solved leetcode daily challenge
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        do{
            string newStr = "";
            for(int i = 0; i<word.length(); i++){
                char ch = word[i];
                newStr+=(ch+1);
            }
            word = word + newStr;
            cout<<word<<endl;
        }while(word.length()<k);

        return word[k-1];
    }
};
