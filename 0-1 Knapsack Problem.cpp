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
    int solveWithTab(int capacity, vector<int> &val, vector<int> &wt){
        int n = val.size();
        vector<vector<int>> dp(capacity+1, vector<int> (n+1, 0));
        
        
        //ananlyse base case
        for(int w = wt[0]; w<=capacity; w++){
            dp[w][0] = val[0]; //important to initialise to work, on some intial value
        }
        
        //range find
        //capacity : w -> 0
        //index  : n-1 -> 0
        
        for(int weight = 0; weight<=capacity; weight++){
            for(int index = 1; index<=n-1; index++){
                //ek case me
                //include exclude patterm
                int inc = 0;
                if(wt[index] <= weight){
                    inc = val[index] + dp[weight-wt[index]][index-1];
                }
                int exc = dp[weight][index-1];
                
                //ans store and return
                dp[weight][index] = max(inc, exc);
            }
        }
        
        return dp[capacity][n-1];
    }
    int solveWithTabSO(int capacity, vector<int> &val, vector<int> &wt){
        int n = val.size();
        
        vector<int> prev(capacity+1, 0);
        vector<int> curr(capacity+1, 0);
        
        //ananlyse base case
        for(int w = wt[0]; w<=capacity; w++){
            //since hum 
            prev[w] = val[0]; //important to initialise to work, on some intial value
        }
        
        //range find
        //capacity : w -> 0
        //index  : n-1 -> 0
        
        for(int weight = 0; weight<=capacity; weight++){
            for(int index = 1; index<=n-1; index++){
                //ek case me
                //include exclude patterm
                int inc = 0;
                if(wt[index] <= weight){
                    inc = val[index] + dp[weight-wt[index]][index-1];
                }
                int exc = dp[weight][index-1];
                
                //ans store and return
                dp[weight][index] = max(inc, exc);
            }
        }
        
        return dp[capacity][n-1];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size()-1;
        //return solveWithRec(val, wt, W, n);
        
        
        //top dowm appproach
        //2d array since capacity and i both are changing
        // vector<vector<int>> dp(W+1, vector<int> (n+1, -1));
        // return solveWithMem(val, wt, W, n, dp);
        
        return solveWithTab(W,val, wt);
        
    }
};
