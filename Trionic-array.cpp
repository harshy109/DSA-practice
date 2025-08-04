class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int q = -1;
        int  p = -1;
        int i = 0;
        bool flag = true;
        while(i+1 < nums.size() && nums[i] < nums[i+1]){
            i++;
        } 
        if(i == 0){
            return false;
        }
        p = i;
        while(i+1 < nums.size() && nums[i] > nums[i+1]){
            i++;
        }
        if(i == p){
            return false;
        }
        q = i;
        while(i+1<nums.size() && nums[i] < nums [i+1]){
            i++;
            // flag = true;
        }
        if(i == q || i != nums.size()-1){
            return false;
        }

        return true;
    }
};
