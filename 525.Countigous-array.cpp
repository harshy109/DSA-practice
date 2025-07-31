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
        //O(n)
        vector<int> sumOf1s;
        vector<int> sumOf0s;
        vector<int> diff;
        int oneSum = 0;
        int zeroSum = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                oneSum++;
            }
            if(nums[i] == 0){
                zeroSum++;
            }
            sumOf1s.push_back(oneSum);
            sumOf0s.push_back(zeroSum);
            int difference = sumOf1s[i] - sumOf0s[i];
            diff.push_back(difference);
        }

        unordered_map<int, int> mp;
        for(int i = 0; i<diff.size(); i++){
            mp[diff[i]]=i;
        }

        int maxLen  = INT_MIN;

        for(int i=0;i<diff.size(); i++){
            int key = diff[i];
            int difference=0;

            if(diff[i] == 0){
                difference = i+1;
            }
            else{
                difference = mp[key] - i;
            }

            maxLen = max(difference, maxLen);
            
        }
        return maxLen;



        //using bruteforce
        //TC = O(n3)

        // int longestSubarrayLength = INT_MIN;
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<nums.size(); j=j+2){
        //         int zeros = countZeros(nums,i,j);
        //         int ones = countOnes(nums,i,j);
        //         if(zeros == ones){
        //             longestSubarrayLength = max(longestSubarrayLength, zeros+ones);
        //         }
        //     }
        // }
        // if(longestSubarrayLength == INT_MIN){
        //     return 0;
        // }
        // return longestSubarrayLength;
    }
};
