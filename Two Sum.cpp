class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // vector<int> ans;
        // for(int i=0; i<arr.size(); i++){
        //     for(int j=i+1; j<arr.size(); j++){
        //         if(arr[i]+arr[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

//latest
        // vector<int> v(2);
        // for(int i=0; i<arr.size(); i++){
        //     for(int j=i+1; j<arr.size(); j++){
        //         if(arr[i]+arr[j]==target ){
        //             v.at(0)=i;
        //             v.at(1)=j;
        //             break;
        //         }
        //     }
        // }
        // return v;

        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                int sum = arr[i]+arr[j];
                mp[sum] = {i,j};
            }
        }

        vector<int> ans;
        for(auto it : mp){
            if(it.first == target){
                ans.push_back(it.second.first);
                ans.push_back(it.second.second);
                break;
            }
        }

        return ans;








        // int n=arr.size();
        // int i,j;
        // vector <int> ans(2);

        // for(i=0; i<n; i++){
        //     for(j=i; j<n; j++){
        //         if(arr[i]+arr[j]==target && i!=j){
        //             ans.at(1)=j;
        //             ans.at(0)=i;
        //         }
        //     }
        // }
        //return ans;
    }
};
