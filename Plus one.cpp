class Solution {
public:
    bool check999(vector<int>& digits){
        for(int i = 0 ; i<digits.size(); i++){
            if(digits[i] != 9){
                return false;
            }
        }
        return true;
    }
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int sum = digits.back() + 1;

        deque<int> q;
        q.push_back(sum%10);

        carry = sum/10;
        for(int i = digits.size()-2; i>=0; i--){
            int sum = digits[i]+carry;
            carry = sum/10;
            q.push_back(sum%10);
        }

        vector<int> ans;

        if(carry != 0){
            q.push_front(carry);
        }
        if(check999(digits)){
            while(!q.empty()){
            ans.push_back(q.front());
            q.pop_front();
        }
        }
        while(!q.empty()){
            ans.push_back(q.back());
            q.pop_back();
        }
        return ans;

        
        // cout<<sum<<endl;
        // if(sum/10 >= 1){
        //     digits.back() = sum/10;
        //     digits.push_back(sum%10);
        // }  
        // else{
        //     digits.back() = sum;
        // }
        //return digits;
    }
};
