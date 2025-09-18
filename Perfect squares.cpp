class Solution {
public:

    int findMinNumbers(int &n, int target){
        if(target == 0){
            return 0;
        }
        int minNums = INT_MAX;
        for(int i = 1; i*i<=n; i++){
            if(target - (i*i) >= 0){
                int ans = findMinNumbers(n, target-(i*i));

                if(ans != INT_MAX){
                    int numsUsed =  1 + ans;
                    minNums = min(minNums, numsUsed);
                }
            }
        }
        return minNums;
    }
    int solveMem(int &n, int target, vector<int>& dp){
        if(target == 0){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int minNums = INT_MAX;
        for(int i = 1; i*i<=n; i++){
            if(target - (i*i) >= 0){
                int ans = solveMem(n, target-(i*i), dp);

                if(ans != INT_MAX){
                    int numsUsed =  1 + ans;
                    minNums = min(minNums, numsUsed);
                }
            }
        }
        dp[target] = minNums;
        return dp[target];
    }
    int numSquares(int n) {
        //return findMinNumbers(n, n);

        vector<int> dp(n+1, -1);
        return solveMem(n, n, dp);
    }
};
