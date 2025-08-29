class Solution {
public:
 
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        ///TLE - O(n2)
        // int  i = 0, j = k-1;
        // vector<int> ans;
        // while(i<arr.size() && j<arr.size()){
        //     priority_queue<int> pq;
        //     for(int index = i; index<=j; index++){
        //         pq.push(arr[index]);
        //     }
        //     ans.push_back(pq.top());
        //     i++, j++;
        // }
        // return ans;

        int  i = 0, j = k-1;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int index = 0; index<k; index++){
            pq.push({arr[index], index});
        }
        i++; 
        j++;
        ans.push_back(pq.top().first);

        while(i<arr.size() && j<arr.size()){
            pq.push({arr[j], j});
            while(pq.top().second < i){
                pq.pop();
            }
            i++;
            j++;  
            ans.push_back(pq.top().first); 
        }
        return ans;











        //last
        // deque<int> q;
        // vector<int> ans;

        // for(int i = 0; i<k; i++){
        //     while(!q.empty() && arr[i]>arr[q.back()]){
        //         q.pop_back();
        //     }
        //     q.push_back(i);
        // }

        // //store ans
        // ans.push_back(arr[q.front()]);

        // for(int i = k; i<arr.size(); i++){
        //     //remove
        //     if(!q.empty() && i - q.front()>=k){
        //         q.pop_front();
        //     }
        //     //addition
        //     while(!q.empty() && arr[q.back()] < arr[i]){
        //         q.pop_back();
        //     }
        //     q.push_back(i);
        //     //store
        //     ans.push_back(arr[q.front()]);
        // }
        // return ans;




        // int maxi = INT_MIN;
        // int index = -1;
        // //q.push_back({INT_MIN, -1});
        // for(int i = 0; i<k; i++){
        //     if(arr[i]>maxi){
        //         maxi = arr[i];
        //         index = i;
        //     }
        // }
        // q.push({maxi, index});
        // int val = q.front().first;
        // ans.push_back(val);
        
        // for(int i = k; i<arr.size(); i++){
        //     ///store ans;
        //         int val = q.front().first;
        //         ans.push_back(val);
            
        //     //removal
        //     if(!q.empty() && i-q.front().second >= k){
        //         q.pop_front();
        //     }
        //     //add
        //     if(q.empty()){
        //         q.push_back({arr[i],i});
        //     }
        //     else if(arr[i] > q.front().first){
        //         q.pop_front();
        //         q.push_back({arr[i],i});
        //     }
        // }
        
        // if(q.empty()){
        //     ans.push_back(0);
        // }
        // else{
        //     ans.push_back(q.front().first);
        // }
        
        // return ans;
    }
};
