class Solution {
public:
    int solveRec(string &s1, string &s2, int i , int j){
        if(i==s1.length() && j==s2.length()){
            return 0;
        }
        else if(i>=s1.length()){
            int sum = 0;
            while(j<s2.length()){
                sum+= s2[j++];
            }
            return sum;
        }
        else if(j>=s2.length()){
            int sum = 0;
            while(i<s1.length()){
                sum+= s1[i++];
            }
            return sum;
        }
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = solveRec(s1, s2, i+1, j+1);
        }
        else{
            int leftDelete = s1[i] + solveRec(s1, s2, i+1, j);
            int rightDelete = s2[j] + solveRec(s1, s2, i, j+1);
            ans = min(leftDelete, rightDelete);
        }
        return ans;
    }
    int solveMem(string &s1, string &s2, int i , int j,  vector<vector<int>>& dp){
        if(i==s1.length() && j==s2.length()){
            return 0;
        }
        if(i==s1.length()){
            int sum = 0;
            // while(j<s2.length()){
            //     sum+= s2[j++];
            // }
            for(int k = j; k<s2.length(); k++){
                sum += s2[k];
            }
            return sum;
        }
        if(j==s2.length()){
            int sum = 0;
            // while(i<s1.length()){
            //     sum+= s1[i++];
            // }
            for(int k = i; k<s1.length(); k++){
                sum += s1[k];
            }
            return sum;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = solveMem(s1, s2, i+1, j+1, dp);
        }
        else{
            int leftDelete = s1[i] + solveMem(s1, s2, i+1, j, dp);
            int rightDelete = s2[j] + solveMem(s1, s2, i, j+1, dp);
            ans = min(leftDelete, rightDelete);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveTab(string &s1, string &s2){
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m][n] = 0;

        for(int col = n-1; col>=0; col-- ){
            dp[m][col] = s2[col] + dp[m][col+1];
        }

        for(int row = m-1; row>=0; row-- ){
            dp[row][n] = s1[row] + dp[row+1][n];
        }

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0;j--){
                int ans = 0;
                if(s1[i] == s2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int leftDelete = s1[i] + dp[i+1][j];
                    int rightDelete = s2[j] + dp[i][j+1];
                    ans = min(leftDelete, rightDelete);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        //return solveRec(s1, s2, 0,0);

        int m = s1.length();
        int n = s2.length();
        //vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        //return solveMem(s1,s2, 0,0,dp);

        return solveTab(s1, s2);
    }
};
