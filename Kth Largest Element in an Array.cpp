class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //O(nlogn)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};
