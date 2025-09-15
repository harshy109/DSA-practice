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

    int solveUsingTabulation(int n){
        //step1 : create a dp array
        vector<int> dp(n+1, -1);

        //analyse base cases and update dp array
        dp[0] = 0;
        if(n == 0){
            return 0;
        }
        dp[1] = 1;

        //check parameter, reverse it and run a loop
        //recursion : n -> 0
        //reverse it : 0 -> n
        for(int i = 2; i<=n; i++){
            //copy paste
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int solveUsingTabSpaceOptimized(int n){
        //step1 : create a dp array
        //vector<int> dp(n+1, -1);

        //analyse base cases and update dp array
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int prev = 0;
        int curr = 1;

        for(int i = 2; i<=n; i++){
            int ans = prev + curr;
            prev = curr;
            curr = ans;
        }

        return curr;
    }

    int fib(int n) {
        //top down approach
        //step1 : create an array, ans pass in function
        // vector<int> dp(n+1, -1);
        // int ans = solveUsingDp(n, dp);
        // return ans;

        //bottom up approach
        // return solveUsingTabulation(n);

        //space optmized
        return solveUsingTabSpaceOptimized(n);


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
