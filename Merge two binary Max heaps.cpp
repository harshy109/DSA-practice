// User function Template for C++

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        vector<int> ans;
        
        int i = 0, j= 0;
        while(i<a.size() && j<b.size()){
            if(a[i] > b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i < a.size()){
            ans.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
};
