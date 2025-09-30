class Solution {
public:
    int solve(vector<int> nums){
        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> v;
        for(int i = 0; i<nums.size()-1; i++){
            int sum = (nums[i] + nums[i+1])%10;
            v.push_back(sum);
        }
        return solve(v);
    }
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        return solve(nums);       
    }
};
