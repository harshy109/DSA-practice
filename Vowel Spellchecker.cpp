class Solution {
public:
    string maskVowels(string s){
        string newstr = "";
        string vowels = "aeiou";
        for(char ch : s){
            if(vowels.find(ch) == string::npos){
                newstr += ch;
            }
            else{
                newstr += '*';
            }
        }
        return newstr;
    }
    string toLower(string s){
        for(char &ch : s){
            if(ch >= 'A' && ch<='Z'){
                ch = ch - 'A' + 'a';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        //if same word found -> add that
        unordered_map<string, string> mp;
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> consonantsMatch;

        for(string s : wordlist){
            string cpy = toLower(s);
            string str = maskVowels(cpy);
            if(mp.find(cpy) == mp.end()){
                mp[cpy] = s;
            }
            if(consonantsMatch.count(str) == 0){
                consonantsMatch[str] = s;
            }
        }

        for(string str : queries){
            if(exact.find(str) != exact.end()){
                ans.push_back(str);
                continue;
            }
            string strcpy = toLower(str);

            if(mp.count(strcpy) != 0){
                ans.push_back(mp[strcpy]);
                continue;
            }
            else{
                string withoutVowel = maskVowels(str);
                if(consonantsMatch.find(withoutVowel) != consonantsMatch.end()){
                    ans.push_back(consonantsMatch[withoutVowel]);
                }
                else{
                    ans.push_back("");
                }
            }
        }

        return ans;

    }
};
