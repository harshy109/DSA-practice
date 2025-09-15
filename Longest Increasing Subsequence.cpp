class Solution {
public:
    int solve(vector<int>& nums, int i , int lastIndex){
        //base case
        if(i >= nums.size()){
            return 0;
        }

        //ek case me solve krunga baki rec karega
        int inc = 0;
        int curr = nums[i];
        if(lastIndex == -1 || curr > nums[lastIndex]){
            inc = 1 + solve(nums, i+1, i);
        }
        int exc = 0 + solve(nums, i+1, lastIndex);
        int finalAns = max(inc, exc);
        return finalAns;
    }
    //2D dp arrray
    int solveMem(vector<int>& nums, int i , int lastIndex, vector<vector<int>>&dp){
        //base case
        if(i >= nums.size()){
            return 0;
        }
        //step3: base case ke bad check if ans already exists
        if(dp[lastIndex+1][i] != -1){
            return dp[lastIndex+1][i];
        }

        //ek case me solve krunga baki rec karega
        int inc = 0;
        int curr = nums[i];
        if(lastIndex == -1 || curr > nums[lastIndex]){
            inc = 1 + solveMem(nums, i+1, i, dp);
        }
        int exc = 0 + solveMem(nums, i+1, lastIndex, dp);
        //step2 : store and return
        dp[lastIndex+1][i] = max(inc, exc);
        return dp[lastIndex+1][i];
    }
    int solveUsingTabulation(vector<int>& nums, int prev, int curr){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0)); //step1+ step2

        //rec range
        //curr = 0-> n
        //prev = -1-> n
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int inc = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    inc = 1 + dp[curr+1][curr+1];
                }
                int exc = 0 + dp[curr+1][prev+1];
                //step2 : store and return
                dp[curr][prev+1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int lastIndex = -1;
        int n = nums.size();
        // return solve(nums, 0, lastIndex);

        //top down
        //step1 : create 2d array
        // vector<vector<int>> dp(n+2, vector<int> (n+1, -1));
        // return solveMem(nums, 0, lastIndex, dp);

        //bottom up
        int curr = 0;
        int prev = -1;
        return solveUsingTabulation(nums, prev, curr);
    }
};
