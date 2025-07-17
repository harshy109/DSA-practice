class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<pair<int, int>> q;
        vector<int> ans;
        int maxi = INT_MIN;
        int index = -1;
        //q.push_back({INT_MIN, -1});
        for(int i = 0; i<k; i++){
            if(arr[i]>maxi){
                maxi = arr[i];
                index = i;
            }
        }
        q.push_back({maxi, index});
        int val = q.front().first;
        ans.push_back(val);
        
        for(int i = k; i<arr.size(); i++){
            ///store ans;
        
            
                int val = q.front().first;
                ans.push_back(val);
            
            //removal
            if(!q.empty() && i-q.front().second >= k){
                q.pop_front();
            }
            //add
            if(q.empty()){
                q.push_back({arr[i],i});
            }
            else if(arr[i] > q.front().first){
                q.pop_front();
                q.push_back({arr[i],i});
            }
        }
        
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(q.front().first);
        }
        
        return ans;
    }
};
