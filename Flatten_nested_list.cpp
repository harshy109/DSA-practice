/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {

    deque<int> flattendQ;

    void flatten(vector<NestedInteger> &nestedList){
        for(auto it : nestedList){
            if(it.isInteger()){
                int item = it.getInteger();
                flattendQ.push_back(item);
            }
            else{
                flatten(it.getList());
            }
        }
    }
public:
    vector<NestedInteger> ans;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        int num = flattendQ.front();
        flattendQ.pop_front();
        return num ;
        
    }
    
    bool hasNext() {
        return !flattendQ.empty();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
