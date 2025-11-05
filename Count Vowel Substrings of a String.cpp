class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    bool isAllVowelString(string str){
        unordered_set<char> st;
        for(char ch : str){
            if(!isVowel(ch)){
                return false;
            }
            else{
                st.insert(ch);
            }
        }
        if(st.size() == 5){
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
        int count = 0;
        int i = 0;
        vector<int> vowel(false);
        
        for(int i = 0; i<word.length(); i++){
            for(int j = i+4; j<word.length(); j++){
                string substr = word.substr(i,j-i+1);
                if(isAllVowelString(substr)){
                    count++;
                    cout<<substr<<endl;
                }
            }
        }
        return count;
    }   
};
