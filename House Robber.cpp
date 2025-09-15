class Solution {
public:
    int findMaxMoney(vector<int>& nums , int i){
        if(i>=nums.size()){
            return 0;
        }
        //include
        int includeAns = nums[i]+findMaxMoney(nums, i+2);
        //exclude
        int excludeAns = 0+findMaxMoney(nums, i+1);
        return max(includeAns , excludeAns);
    }
    int solveWithRec(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        //include-exclude
        int includeAns = nums[i]+solveWithRec(nums, i+2, dp);
        int excludeAns = 0+solveWithRec(nums, i+1, dp);
        dp[i] = max(includeAns , excludeAns);
        return dp[i];
    }

    int solveWithTabulation(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+10, 0);

        dp[nums.size()] = 0;

        //recursion : 0->n
        //reverse : n -> 0
        for(int i=n-1; i>=0; i--){
            //cpopy paste
            int includeAns = nums[i] + dp[i+2];
            int excludeAns = 0 + dp[i+1];
            dp[i] = max(includeAns , excludeAns);
        }
        return dp[0];
    }

    int solveWithTabulationSpaceOptimised(vector<int>& nums){
        int n = nums.size();

        int next1 = 0;
        int next2 = 0;

        //recursion : 0->n
        //reverse : n -> 0
        for(int i=n-1; i>=0; i--){
            //copy paste
            int includeAns = nums[i] + next2;
            int excludeAns = 0 + next1;
            int curr = max(includeAns , excludeAns);
            
            //shifting , bhulna nahi
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
        // int maxi = INT_MIN;
        // int maxMoney = findMaxMoney(nums, 0);
        // return maxMoney;

        //top down
        // int n = nums.size();
        // vector<int> dp(n+1, -1);
        // int ans = solveWithRec(nums, 0, dp);
        // return ans;

        //bottom up/tabulation
        // return solveWithTabulation(nums);

        //space optiized;
        return solveWithTabulationSpaceOptimised(nums);
    }

};
