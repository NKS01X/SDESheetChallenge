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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int Len = 0;
        ListNode* last = head;
        while(last->next != nullptr) {
            ++Len;
            last = last->next;
        } 
        Len++;
        // cout << Len << endl;
        k %= Len;
        if(!k) return head; 
        
        last->next = head;
        int curr_head = Len - k; 
        for(int i = 0;i < curr_head - 1; ++i) 
            head = head->next; //impossible ki wo  nullptr ho
        ListNode* curr = head->next;
        head->next = nullptr;
        return curr;
    }
};
