class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        if(head==NULL || head->next == NULL || head->next->next == NULL) return ans;

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* forward = curr->next;

        int first = -1, last = -1;
        int minDiff = INT_MAX;

        int position = 1;
        while(forward!=NULL && curr!=NULL){
            bool isCP = ((curr->val > prev->val && curr->val > forward->val) || 
                        (curr->val < prev->val && curr->val < forward->val)) ? true : false;

            if(isCP && first == -1){
                first = position;
                last = position;
            }
            else if(isCP){
                minDiff = min(minDiff,position-last);
                last = position;
                cout<<minDiff<<endl;
            }
            position++;
            prev = curr;
            curr=forward;
            forward = forward->next;
        }

        if(first == last) return ans;

        ans[0]=minDiff;
        ans[1]=last - first;
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> ans = {-1,-1};
//         if(head==NULL || head->next == NULL || head->next->next == NULL) return ans;

//         vector<int> criticalPoints(0);

//         ListNode* prev = head;
//         ListNode* curr = prev->next;
//         ListNode* forward = curr->next;

//         int position = 1;
//         while(forward!=NULL && curr!=NULL){
//             if((curr->val > prev->val && curr->val > forward->val) || (curr->val < prev->val && curr->val < forward->val)){
//                 position++;
//                 criticalPoints.push_back(position);
                
//             }
//             else{
//                 position++;
//             }
//             prev = curr;
//             curr=forward;
//             forward = forward->next;
//         }
//         if(criticalPoints.size() < 2) return ans;
//         cout<<criticalPoints.size()<<endl;

//         int minDiff = INT_MAX;
//         int maxDiff = INT_MIN;
//         for(int i = 0; i<criticalPoints.size(); i++){
//             for(int j = i+1; j<criticalPoints.size(); j++){
//                 int diff = abs(criticalPoints[i]-criticalPoints[j]);
//                 minDiff = min(minDiff, diff);
//                 maxDiff = max(maxDiff, diff);  
//             }
//         }

//         ans[0]=minDiff;
//         ans[1]=maxDiff;
//         return ans;
//     }
// };
