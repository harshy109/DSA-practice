class Solution {
public:
    bool solve(string& s, vector<string>& wordDict) {
        // base case
        if(s.length() == 0) {
            return true;
        }
        for(string word : wordDict) {
            if (s.size() == 0) {
                return true;
            }
            //auto it = s.find(word) ? s.find(word) : string ::npos;
            if (s.find(word) != string::npos) {
                string s1 = s.substr(0, word.length());
                string s2 = s.substr(word.length());
                //cout<<s1<<" and "<<s2<<endl;
                string newStr = s1 + s2;
                solve(newStr, wordDict);
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};
