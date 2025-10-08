class Solution {
public:
    bool isSuccessfull(long long a, long long b, long long success){
        int s = 1, e = b;
        while(s <= e){
            int mid = s +(e-s)/2;
            if(mid*a >= success){
                return true;
            }
            else if(mid*a < success){
                s = mid + 1;
            }
        }
        return false;
    }
    bool checkSuccessRec(int s, int e, long long a, long long success){
        //base case
        if(s > e){
            return false;
        }

        long long mid = s +(e-s)/2;
        if(mid*a >= success){
            return true;
        }
        bool ans = checkSuccessRec(mid+1, e, a, success);
        return ans;

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;

        sort(potions.begin(), potions.end());

        for(int i = 0; i<spells.size(); i++){
            int count = 0; 
            for(int j = 0; j<potions.size(); j++){
                vector<long long> dp(potions[j]+1, -1);
                if(checkSuccessMem(1, potions[j], spells[i], success, dp)){
                    count = potions.size() - j;
                    break;
                }
                // if(isSuccessfull(spells[i], potions[j], success)){
                //     count = potions.size() - j;
                //     break;
                // }
                

                // long long int prod = spells[i] * potions[j];
                // if(prod >= success){
                //     count = potions.size() - j;
                //     break;
                // }

                // long long int prod = spells[i] * potions[j];
                // if(prod >= success){
                //     count++;
                // }
            }
            pairs.push_back(count);
        }
        return pairs;
    }
};
