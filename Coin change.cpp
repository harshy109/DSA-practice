class Solution {
public:
    int findNumOfCoins(vector<int>& coins, int amount){
        //Base case
        if(amount == 0){
            return 0;
        }
        //Setting minCoins to INT_MAX , to find min coins
        int minCoins = INT_MAX;
        
        //looping over coins array to find min coins
        for(int i=0; i<coins.size(); i++){
            //valid coin constraint
            if(coins[i]<=amount){
                int REans = findNumOfCoins(coins, amount-coins[i]);

                if(REans != INT_MAX ){
                    int coinsUsed = 1+REans;
                    minCoins = min(minCoins, coinsUsed);
                }
            }
        }
        return minCoins;
    }
    int solveMem(vector<int>& coins, int amount, vector<int> &dp){
        //Base case
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return  dp[amount] ;
        }
        //Setting minCoins to INT_MAX , to find min coins
        int minCoins = INT_MAX;
        
        //looping over coins array to find min coins
        for(int i=0; i<coins.size(); i++){
            //valid coin constraint
            if(coins[i]<=amount){
                int REans = solveMem(coins, amount-coins[i], dp);

                if(REans != INT_MAX ){
                    int coinsUsed = 1+REans;
                    minCoins = min(minCoins, coinsUsed);
                }
            }
        }
        dp[amount] = minCoins;
        return  dp[amount] ;
    }
    int solveUsingTabulation(vector<int> &coins, int amount){
        //create dp array
        vector<int> dp(amount+1 , -1);

        //analyse base cases amd update array
        dp[0] = 0;

        //check pararmeter and reverse it adn run loop
        for(int amt = 1; amt<=amount; amt++){
            //logic copy paste
            int minCoins = INT_MAX;
        
            //looping over coins array to find min coins
            for(int i=0; i<coins.size(); i++){
                //valid coin constraint
                if(coins[i]<=amt){
                    int REans =dp[amt-coins[i]];

                    if(REans != INT_MAX ){
                        int coinsUsed = 1 + REans;
                        minCoins = min(minCoins, coinsUsed);
                    }
                }
            }
            dp[amt] = minCoins;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans  = findNumOfCoins(coins, amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // return ans;


        // vector<int> dp(amount+1, -1);
        // int ans = solveMem(coins, amount, dp);
        int ans = solveUsingTabulation(coins, amount);

        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
