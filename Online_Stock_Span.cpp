class StockSpanner {
public:
    stack<pair<int, int>> s;
    int i = 1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        
        if(s.empty()){
            s.push({INT_MAX, 0});
            s.push({price,i});
            i++;
            return count;
        }
        while(!s.empty() && s.top().first<=price){
            // count++;
            s.pop();
        }
        if(s.empty()) return i;
        count = i - s.top().second;
        s.push({price, i}); i++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
