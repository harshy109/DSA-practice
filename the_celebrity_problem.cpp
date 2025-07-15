class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        //create a stack
        stack<int> s;
        int n = mat.size();
        for(int i = 0; i<n ; i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int A = s.top(); s.pop();
            int B = s.top(); s.pop();
            
            if(mat[A][B]==1){
                //discard A;
                s.push(B);
            }
            else if(mat[B][A]){
                s.push(A);
            }
        }
        
        if(s.empty()) return -1;
        
        //ab sirf ek bacha hai
        int mightBe = s.top();
        for(int col = 0; col<n; col++){
            if(mightBe!=col && mat[mightBe][col]!=0){
                return -1;
            }
        }
        for(int row = 0; row<n; row++){
            if(mightBe!=row && mat[row][mightBe]==0){
                return -1;
            }
        }
        return mightBe;
        // code here
        // int n = mat.size();
        // bool celebrityExists = false;
        // unordered_map<int, int> mp;
        // for(int i = 0; i<mat.size(); i++){
        //     for(int j = 0; j<mat[i].size(); j++){
        //         if(i!=j && mat[i][j]=='1'){
        //             mp[j]++;
        //         }
        //     }
        // }
        // int celebrity= -1;
        // for(auto it : mp){
        //     cout<<it.second<<endl;
        //     if(it.second == n-1 ){
        //         //celebrityExists = !celebrityExists;
        //         //if(celebrityExists){
        //             celebrity = it.first;
        //             cout<<it.first<<endl;
        //         //}
        //     }
        // }
        // return celebrity;
    }
};
