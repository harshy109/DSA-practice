class Solution {
public:
    void findMaxProfit(vector<int>& prices,int i, int& minPrice, int& maxProfit){
        if(i==prices.size()) return;

        if(prices[i]<minPrice){
            minPrice = prices[i];
        }
        if((prices[i]-minPrice )> maxProfit){
            maxProfit = prices[i]-minPrice;
        }
        findMaxProfit(prices, i+1, minPrice, maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        //O(n2) - TLE
        int maxProfit = INT_MIN;
        for(int i = 0; i<prices.size(); i++){
            for(int j = i+1; j<prices.size(); j++){
                if(prices[j] > prices[i]){
                    int profit = prices[j] - prices[i];
                    maxProfit = max(profit, maxProfit);
                }
            }
        }
        if(maxProfit == INT_MIN){
            return 0;
        }

        return maxProfit;
        

        // int minPrice = INT_MAX;
        // int index = 0;
        // for(int i = 0; i<prices.size(); i++){
        //     if(prices[i] < minPrice){
        //         minPrice = prices[i];
        //         index = i;
        //     }
        // }
        // int maxPrice = INT_MIN;

        // for(int i = index; i<prices.size(); i++){
        //     maxPrice = max(maxPrice, prices[i]);
        // }

        // return maxPrice - minPrice;



        // int minPrice = INT_MAX;
        // int maxProfit = INT_MIN;
        // findMaxProfit(prices, 0, minPrice, maxProfit);
        // return maxProfit;


        // int buyDay = 0;
        // int sellPrice = INT_MIN;
        // for(int i = 0; i<prices.size(); i++){
        //     //buyPrice = min(prices[i], buyPrice);
        //     if(prices[i]<buyPrice){
        //         buyPrice = prices[i];
        //         buyDay = i;
        //     }
        // }

        // if(buyDay==prices.size()-1) return 0;

        // for(int i = buyDay; i<prices.size(); i++){
        //     if(prices[i]>sellPrice){
        //         sellPrice=prices[i];
        //     }
        // }

        // int profit = sellPrice - buyPrice;
        // return profit;

    }
};
