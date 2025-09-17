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
    int countWays(int n, int k) {
        //return solveRec(n, k);
        
        vector<int> dp(n+1, -1);
        return solveMem(n, k ,dp);
    }
};
