vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n,-1);
    for(int i = 0; i<arr.size(); i++){
        int target = arr[i];
        for(int j = i+1; j<arr.size(); j++){
            if(arr[j]<target){
                ans[i]=arr[j];
                break;
            }
            else if(arr[j] > target){
                continue;
            }
            else if(j==arr.size()-1 && arr[j] > target){
                ans[i] = -1;
            }
        }
    }
    return ans;
}
