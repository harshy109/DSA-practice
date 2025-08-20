class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //O(n) - TC
        //O(n) - SC
        priority_queue<int> pq; //max heap

        for(int i = 0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        for(int i = 0; i<k-1; i++){
            pq.pop();
        }

        return pq.top();
        //O(nlogn)
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n-k];
    }
};
