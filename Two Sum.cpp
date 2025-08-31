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


        //using map - 30-08-25
        // unordered_map<int, pair<int, int>> mp;

        // for(int i = 0; i<arr.size(); i++){
        //     for(int j = i+1; j<arr.size(); j++){
        //         int sum = arr[i]+arr[j];
        //         mp[sum] = {i,j};
        //     }
        // }

        // vector<int> ans;
        // for(auto it : mp){
        //     if(it.first == target){
        //         ans.push_back(it.second.first);
        //         ans.push_back(it.second.second);
        //         break;
        //     }
        // }
        // return ans;


        //31-8-25
        // unordered_map<int, int> mp;
        // for(int i = 0; i<arr.size(); i++){
        //     mp[i] = arr[i];
        // }

        // vector<int> ans;
        // bool found = false;

        // for(int i = 0; i<arr.size(); i++){
        //     int currElement = arr[i];
        //     int valueToFind = target - currElement;
        //     unordered_map<int, int>::iterator it = mp.find(valueToFind);
            
        //     for(auto it : mp){
        //         if(it.first != i && it.second == valueToFind){
        //             ans.push_back(i);
        //             ans.push_back(it.first);
        //             found = true;
        //             break;
        //         }
        //     }
        //     if(found) break;
        // }
        // return ans;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        vector<int> ans;
        bool found = false;

        for(int i = 0; i<arr.size(); i++){
            int currElement = arr[i];
            int valueToFind = target - currElement;
            if( mp.find(valueToFind) != mp.end() ){
                if(currElement == valueToFind && mp[valueToFind].size()> 1){
                    ans.push_back(mp[valueToFind][0]);
                    ans.push_back(mp[valueToFind][1]);
                    break;
                }       
                if(currElement == valueToFind && mp[valueToFind].size() == 1){
                    continue;
                }
                else{
                    ans.push_back(mp[currElement][0]);
                    ans.push_back(mp[valueToFind][0]);
                    break;
                }
            }
        }
        return ans;
        
    }
};
