class Solution {
public:
    int solveRec(int s, int e){
        //base case
        if(s >= e){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = s; i<=e; i++){
            ans = min(ans, i+ max(solveRec(s, i-1), solveRec(i+1, e)));
        }
        return ans;
    }
    int solveMem(int s, int e, vector<vector<int>> &dp){
        //base case
        if(s >= e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i = s; i<=e; i++){
            ans = min(ans, i+ max(solveMem(s, i-1, dp), solveMem(i+1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    int solveTabulation(int n){
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int s = n; s>=1; s--){
            for(int e = 1; e<=n; e++){
                if(s<e){
                    int ans = INT_MAX;
                    for(int i = s; i<=e; i++){
                        ans = min(ans, i+ max(dp[s][i-1], dp[i+1][e]));
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        //return solveRec(1, n);
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMem(1, n, dp);

        return solveTabulation(n);
    }
};
