class Solution {
  public:
    long long mod = 1e9+7;
    int solveRec(int n , int  k){
        //base case
        if(n == 1){
            return k;
        }
        if(n == 2){
            return k*k;
        }
        
        //ek case me ,baki recursion krega
        int ans = (k-1) * (solveRec(n-1, k) + solveRec(n-2, k));
        return ans;
    }
    //1D dp
    int solveMem(int n , int k, vector<int>& dp){
        //base case
        if(n == 1){
            return k;
        }
        if(n == 2){
            return (k*k)%mod;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        //ek case me ,baki recursion krega
        dp[n] = ((k-1) * (solveMem(n-1, k, dp)%mod + solveMem(n-2, k, dp)%mod)%mod)%mod;
        return dp[n];
    }
    int solveTabulation(int n, int k){
        vector<int> dp(n+1, 0);
        
        dp[1] = k;
        dp[2] = (k*k)%mod;
        
        //check range
        ///n : n->1
        for(int i = 3; i<=n; i++){
            dp[i] = ((k-1) * (dp[i-1]%mod + dp[i-2]%mod)%mod)%mod;
        }
        return dp[n];
    }
    int solveTabulationSO(int n, int k){
        
        int prev2 = k;
        if( n == 1) return prev2;
        int prev1 = (k*k)%mod;
        if(n == 2) return prev1;
        
        //check range
        ///n : n->1
        for(int i = 3; i<=n; i++){
            int curr = ((k-1) * (prev1%mod + prev2%mod)%mod)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int countWays(int n, int k) {
        //return solveRec(n, k);
        
        // vector<int> dp(n+1, -1);
        // return solveMem(n, k ,dp);
        
        return solveTabulationSO(n,k);
    }
};
