class Solution {
public:
    bool solve(string s, vector<string>& wordDict) {
        // base case
        if(s.length() == 0) {
            return true;
        }
        for(int i = 0; i<wordDict.size(); i++) {
            string word = wordDict[i];
            auto it = s.rfind(word,0);
            if (it==0) {
                string str = s.substr(word.length());
                bool ans = solve(str , wordDict);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    bool check( vector<string>& wordDict, string s){
        for(auto word : wordDict){
            if(s == word){
                return true;
            }
        }
        return false;
    }
    bool solveRec(string s, vector<string>& wordDict, int start) {
        // base case
        if(start == s.length()) {
            return true;
        }
        string word = "";
        bool flag = false;
        for(int i = start; i<s.length(); i++) {
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solveRec(s, wordDict, i+1);
            }
        }
        return flag;
    }
    bool solveMem(string s, vector<string>& wordDict, int start, vector<int> &dp) {
        // base case
        if(start >= s.length()) {
            return true;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        string word = "";
        bool flag = false;
        for(int i = start; i<s.length(); i++) {
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solveMem(s, wordDict, i+1, dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }
    // bool solveTab()
    bool wordBreak(string s, vector<string>& wordDict) {
        //return solve(s, wordDict);
        vector<int> dp(s.size()+1, -1);
        // return solveRec(s, wordDict, 0);
        return solveMem(s, wordDict, 0, dp);
    }
};
