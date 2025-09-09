class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int maxLen = 0;
        for(int i = 0; i<arr.size(); i++){
            int n = 0;
            int sum = 0;
            for(int j = i; j<arr.size(); j++){
                sum += arr[j];
                n++;
                if(sum == 0){
                    maxLen = max(maxLen, n);
                }
            }
        }
        return maxLen;
    }
};
