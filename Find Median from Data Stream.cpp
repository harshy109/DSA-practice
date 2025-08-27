class MedianFinder {
public:
    // vector<int> v;
    priority_queue<int, vector<int> , greater<int> > minHeap;
    priority_queue<int> maxHeap;
    double median = 0.0;
    MedianFinder() {
        
    }    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            maxHeap.push(num);
            median = num;
        }
        else{
            if(num > median){
                minHeap.push(num);
                int minSize = maxHeap.size();
                int maxSize = minHeap.size();
                if(abs(minSize - maxSize) > 1){
                    int element = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(element);
                } 
            }
            else{
                maxHeap.push(num);
                int minSize = maxHeap.size();
                int maxSize = minHeap.size();
                if(abs(minSize - maxSize) > 1){
                    int element = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(element);
                }
            }
        }
       
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            int first = maxHeap.top();
            int second = minHeap.top();
            median = ( first + second )/2.0;
            cout<<"Equal size: "<<median<<endl;
        }
        else if(maxHeap.size() > minHeap.size()){
            median = maxHeap.top()/1.0;
            cout<<maxHeap.top()<<" ";
            cout<<"Max heap greater size: "<<median<<endl;
        }
        else{
            median = minHeap.top()/1.0;
            cout<<minHeap.top()<<" ";
            cout<<"Min heap greater size: "<<median<<endl;
        }
        
        return median;


        // double median;
        // priority_queue<int, vector<int> , greater<int> > p(pq);
        // vector<int> v;

        // //insert every time all the elements 
        // while(!p.empty()){
        //     v.push_back(p.top());
        //     p.pop();
        // }

        // int len = v.size();
        // if(len%2 != 0){
        //     int mid = len/2;
        //     median = v[mid];
        // }
        // else{
        //     int mid = len/2;
        //     int mid_1 = mid-1;

        //     double avg = (v[mid] + v[mid_1])/2.0;
        //     median = avg;
        // }
        // return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
