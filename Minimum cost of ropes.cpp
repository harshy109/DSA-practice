class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            long long sum = first + second;
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};
