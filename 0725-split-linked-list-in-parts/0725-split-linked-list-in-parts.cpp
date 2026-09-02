/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }
        int base = n / k;
        int extra = n % k;

        vector<ListNode*> ans(k, nullptr);
        curr = head;

        for(int i = 0; i < k && curr != nullptr; i++){
            ans[i] = curr;
            int size = base + (extra > 0 ? 1 : 0);
            extra--;

            for(int j = 1; j < size; j++){
                curr = curr->next;
            }
            ListNode* nxt = curr->next;
            curr->next = nullptr;
            curr = nxt;
        }
        return ans;
    }
};