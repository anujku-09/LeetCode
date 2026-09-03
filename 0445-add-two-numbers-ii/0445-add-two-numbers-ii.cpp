class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1, s2;
        for(ListNode* p = l1; p; p = p->next) s1.push(p->val);
        for(ListNode* p = l2; p; p = p->next) s2.push(p->val);

        int carry = 0;
        ListNode* head = nullptr;
        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};