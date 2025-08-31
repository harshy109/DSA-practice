class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        //Bruteforce = O(n*f)
        // vector<int> ans;
        
        // for(int i = 0; i<order.size(); i++){
        //     for(int j = 0; j<friends.size(); j++ ){
        //         if(order[i] == friends[j]){
        //             ans.push_back(order[i]);
        //         }
        //     }
        // }
        // return ans;

        //using set - O(n)
        unordered_set<int> s;
        vector<int> ans;
        
        for(int i = 0; i<friends.size(); i++){
            s.insert(friends[i]);
        }

        for(int i=0; i<order.size(); i++){
            if(s.find(order[i])!=s.end()){
                ans.push_back(order[i]);
            }
        }

        return ans;
    }
};
