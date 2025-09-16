class Solution {
  public:
    int solveWithRec(vector<int> &val, vector<int> &wt, int capacity, int i){
        //base case
        if(i == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            return 0;
        }
        
        //ek case me
        //include exclude patterm
        int inc = 0;
        if(wt[i] <= capacity){
            inc = val[i] + solveWithRec(val, wt, capacity-wt[i], i-1 );
        }
        int exc = solveWithRec(val, wt, capacity, i-1 );
        int finalAns = max(inc, exc);
        return finalAns;
    }
    int solveWithMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp){
        //base case
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            return 0;
        }
        //check existing ans
        if(dp[capacity][index] != -1){
            return dp[capacity][index];
        }
        
        //ek case me
        //include exclude patterm
        int inc = 0;
        if(wt[index] <= capacity){
            inc = val[index] + solveWithMem(val, wt, capacity-wt[index], index-1 , dp);
        }
        int exc = solveWithMem(val, wt, capacity, index-1 , dp);
        
        //ans store and return
        dp[capacity][index] = max(inc, exc);
        return dp[capacity][index];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size()-1;
        //return solveWithRec(val, wt, W, n);
        
        
        //top dowm appproach
        //2d array since capacity and i both are changing
        vector<vector<int>> dp(W+1, vector<int> (n+1, -1));
        return solveWithMem(val, wt, W, n, dp);
        
        
    }
};
