class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> v;
        
        int  i = 0;
        while(i<text.length()){
            string temp="";
            while(i<text.length() && text[i] != ' '){
                temp+=text[i];
                i++;
            }
            i++;
            v.push_back(temp);
        }
        int count = v.size();
        for(auto &it : v){
            for(char ch : brokenLetters){
                if(it.contains(ch)){
                    it="";
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};
