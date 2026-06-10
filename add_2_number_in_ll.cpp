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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* head = l1;

        const auto& sum = [](int& tot,int& rem) {
            int val = tot%10;
            tot /= 10;
            rem = tot;
            tot = val;
        };
        
        ListNode* prev1 = nullptr; 
        
        while(l1 != nullptr && l2 != nullptr) {
            int tot = l1->val + l2->val + rem;
            sum(tot,rem);
            l1->val = tot;
            
            prev1 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(!l1 && !l2) {
            if(rem) {
                ListNode* tail = new ListNode(rem);
                prev1->next = tail; 
            }
        } else if(!l1) {
            prev1->next = l2; 
            ListNode* h = prev1;
            
            while(l2) {
                int tot = l2->val + rem;
                sum(tot,rem);
                l2->val = tot;
                h = l2;
                l2 = l2->next;
            }
            if(rem) {
                ListNode* tail = new ListNode(rem);
                h->next = tail;
            }
        } else if(!l2) {
            ListNode* h = prev1;
            
            while(l1) {
                int tot = l1->val + rem;
                sum(tot,rem);
                l1->val = tot;
                h = l1;
                l1 = l1->next;
            }
            if(rem) {
                ListNode* tail = new ListNode(rem);
                h->next = tail;
            }
        }

        return head;
    }
};