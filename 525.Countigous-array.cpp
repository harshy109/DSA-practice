class Solution {
public:
    int countZeros(vector<int> &nums,int s, int e){
        int zeros= 0;
        for(int i = s; i<=e; i++){
            if(nums[i] == 0){
                zeros++;
            }
        }
        return zeros;
    }
    int countOnes(vector<int> &nums,int s, int e){
        int ones = 0;
        for(int i = s; i<=e; i++){
            if(nums[i] == 1){
                ones++;
            }
        }
        return ones;
    }
    int findMaxLength(vector<int>& nums) {
        //using bruteforce
        //TC = O(n3)
        int longestSubarrayLength = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j=j+2){
                int zeros = countZeros(nums,i,j);
                int ones = countOnes(nums,i,j);
                if(zeros == ones){
                    longestSubarrayLength = max(longestSubarrayLength, zeros+ones);
                }
            }
        }
        if(longestSubarrayLength == INT_MIN){
            return 0;
        }
        return longestSubarrayLength;
    }
};
