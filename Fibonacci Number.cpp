class Solution {
public:
    int rec(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        int ans = rec(n-1) + rec(n-2);
        return ans;
    }

    int solveUsingDp(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        //step3: base case ke bad check if ans already exists and return
        if(dp[n] != -1){
            return dp[n];
        } 


        //step2: store ans and return ans
        dp[n] = solveUsingDp(n-1, dp) + solveUsingDp(n-2, dp);
        return dp[n];
    }

    int fib(int n) {

        //step1 : create an array, ans pass in function
        vector<int> dp(n+1, -1);
        int ans = solveUsingDp(n, dp);
        return ans;


        //LOOP
        // int fib1=0;
        // int fib2=1;
        // if(n==0){
        //     return 0;
        // }
        // for(int i=2; i<=n; i++){
        //     int fib3=fib1+fib2;
        //     fib1=fib2;
        //     fib2=fib3;
        // }
        // return fib2;
    }
};
