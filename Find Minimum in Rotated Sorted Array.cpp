class Solution {
public:
    int binarySearch(vector<int> &nums){
        int n = nums.size()-1;
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;

        while(s<=e){
            if(mid-1 >=0 && nums[mid] < nums[mid-1] && mid+1<nums.size() && nums[mid] < nums[mid+1]){
                return nums[mid];
            }
            else if(mid-1 >=0 && nums[mid] > nums[mid-1] && mid+1<nums.size() && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid] < nums[s]){
                //line B
                e = mid-1; 
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        if(nums[0]<nums[n]){
            return nums[0];
        }
        return nums[n];
    }
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }
};
