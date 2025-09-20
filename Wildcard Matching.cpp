class Solution {
public:
    bool solveRec(string &s, string &p, int i, int j){
        //base case
        if(i==s.length() && j==p.length()){
            //sare match ho gaye
            return true;
        }
        if(j>=p.length()){
            //pattern khtm ho gya hai, but string khtm nhi hui
            return false;
        }
        if(i>=s.length()){
            //pattern abhi bhi bacha hai
            for(int k = j; k<p.length(); k++){
                //koi  bhi ek * nhi tha
                if(p[k] != '*'){
                    return false;
                }
            }
            //sare hi * the
            return true;
        }
        //main logic
        //match 
        if(s[i] == p[j] || p[j] == '?'){
            return solveRec(s,p, i+1, j+1);
        }
        else if(p[j]=='*'){
            return solveRec(s,p,i+1, j) || solveRec(s,p, i, j+1);
        }
        else{
            return false;
        }
    }
    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i==s.length() && j==p.length()){
            //sare match ho gaye
            return true;
        }
        if(j>=p.length()){
            //pattern khtm ho gya hai, but string khtm nhi hui
            return false;
        }
        if(i>=s.length()){
            //pattern abhi bhi bacha hai
            for(int k = j; k<p.length(); k++){
                //koi  bhi ek * nhi tha
                if(p[k] != '*'){
                    return false;
                }
            }
            //sare hi * the
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //main logic
        //match 
        bool ans = false; 
        if(s[i] == p[j] || p[j] == '?'){
            ans = solveMem(s,p, i+1, j+1, dp);
        }
        else if(p[j]=='*'){
            ans = solveMem(s,p,i+1, j, dp) || solveMem(s,p, i, j+1,dp);
        }
        else{
            ans = false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }//2D dp
    bool isMatch(string s, string p) {
        //return solveRec(s,p, 0, 0);

        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1,-1));
        return solveMem(s,p, 0, 0, dp);
    }
};
