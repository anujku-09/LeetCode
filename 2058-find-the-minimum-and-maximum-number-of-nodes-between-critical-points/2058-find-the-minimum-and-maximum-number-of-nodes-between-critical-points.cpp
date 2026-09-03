class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        int idx = 1;

        while(curr && curr->next){
            bool isMax = (curr->val > prev->val && curr->val > curr->next->val);
            bool isMin = (curr->val < prev->val && curr->val < curr->next->val);

            if(isMax || isMin){
                if(first == -1){
                    first = idx;
                }
                else{
                    minDist = min(minDist, idx - last);
                }
                last = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if(minDist == INT_MAX){
            return {-1, -1};
        }
        return {minDist, last - first};
    }
};