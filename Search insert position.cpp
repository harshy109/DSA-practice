class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                ans = mid;
                e = mid-1;
            }
            else{
                ans = mid+1;
                s = mid+1;
            }
        }
        return ans;
    }
};
