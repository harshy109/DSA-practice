class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int N = 0;
        ListNode* it = head;
        while(it!=NULL){
            N++;
            it=it->next;
        }
        int partSize = N/k;
        int extraNodes = N%k;
        
        it = head;

        vector<ListNode*> ans(k, nullptr);
        for(int i = 0; i<k && it ; i++){
            ans[i]=it;
            int currPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;
            for( int j = 0; j< currPartSize-1; j++){
                it= it->next;
            }
            ListNode* nextPartStart = it->next;
            it->next = NULL;
            it = nextPartStart;
            // int partSize = bucketSize + (extraNode-- ? 1 : 0);
            // ListNode* part = head;
            // for(int j = 0; j<partSize; j++){
            //     part=part->next;
            //     head = part->next;
            // }
            // part->next = NULL;
        }
        return ans;
    }
};
