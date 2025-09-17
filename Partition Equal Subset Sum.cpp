class Solution {
public:
    bool solve(vector<int>& nums, int halfSum , int i, int total ){
        if(i>=nums.size()){
            return false;
        }
        if(total==halfSum){
            return true;
        }
        if(total>halfSum){
            return false;
        }
        bool include = solve(nums, halfSum , i+1, total+nums[i]);
        bool exclude = solve(nums, halfSum , i+1, total);

        return include || exclude;
    }
    bool solveMem(vector<int>& nums, int halfSum , int i, int total, vector<vector<int>> &dp ){
        if(i>=nums.size()){
            return false;
        }
        if(total==halfSum){
            return true;
        }
        if(total>halfSum){
            return false;
        }

        if(dp[i][total] != -1){
            return dp[i][total];
        }
        bool include = solveMem(nums, halfSum , i+1, total+nums[i], dp);
        bool exclude = solveMem(nums, halfSum , i+1, total, dp);

        dp[i][total]= include || exclude;
        return dp[i][total];
    }//2D dp array

    bool solveTab(vector<int>& nums, int halfSum){
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int> (halfSum+100, 0));

        for(int row = 0; row<=n; row++){
            dp[row][halfSum] = 1;
        }

        //range
        //i = 0->n
        //total = 0-> halfsum/ total
        for(int i = n-1; i>=0; i--){
            for(int t = halfSum-1; t>=0; t--){
                bool include = dp[i+1][t+nums[i]];
                bool exclude = dp[i+1][t];

                dp[i][t] = include || exclude;
            }
        }
        return dp[0][0];
    }
    bool solveTabSO(vector<int>& nums, int halfSum){
        int n = nums.size();

        vector<int> next(halfSum+1, 0);
        vector<int> curr(halfSum+1, 0);

        next[halfSum] = 1;

        //range
        //i = 0->n
        //total = 0-> halfsum / total
        for(int i = n-1; i>=0; i--){
            for(int t = halfSum; t>=0; t--){
                bool include = 0;
                if(t+nums[i] <= halfSum){
                    include = next[t + nums[i]]; 
                }
                bool exclude = next[t];

                curr[t] = include || exclude;
            }
            next = curr;
        }
        return curr[0];
    }   
    bool solveTabSO2(vector<int>& nums, int halfSum){
        int n = nums.size();

        //vector<int> next(halfSum+1, 0);
        vector<int> curr(halfSum+1, 0);

        curr[halfSum] = 1;

        //range
        //i = 0->n
        //total = 0-> halfsum / total
        for(int i = n-1; i>=0; i--){
            for(int t = 0; t<=halfSum; t++){
                bool include = 0;
                if(t+nums[i] <= halfSum){
                    include = curr[t + nums[i]]; 
                }
                bool exclude = curr[t];

                curr[t] = include || exclude;
            }
            //next = curr;
        }
        return curr[0];
    }    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        if((sum%2)!=0){
            return false;
        }
        int halfSum = sum/2;
        int total = 0;

        //return solve(nums, halfSum , 0, total);
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        // return solveMem(nums,halfSum, 0, total,dp);

        //return solveTabulation(nums, halfSum);

        return solveTabSO2(nums, halfSum);
    }
};
