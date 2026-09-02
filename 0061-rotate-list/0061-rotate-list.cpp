class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;

        tail->next = head;
        int steps = len - k;
        ListNode* curr = head;
        while(--steps){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};