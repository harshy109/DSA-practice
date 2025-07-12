class MinStack {
public:
    vector<pair<int, int>> v;
    MinStack() {
       
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
        }
        else{
            int minValue = min(val, v.back().second);
            v.push_back({val, minValue}); 
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};
