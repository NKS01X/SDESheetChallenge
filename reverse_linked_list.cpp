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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head;
        if(prev == nullptr || prev->next == nullptr) {
            return prev;
        }
        //that means here the next is not nullptr
        curr = prev->next;
        while(curr != nullptr && curr->next != nullptr) {
            //now   
            ListNode* nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
        }
        head->next = nullptr;
        curr->next = prev;
        return curr;
    }
};