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

const int N = 1e5 + 1;
static int s[N/2]; 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //for O(n) we will reverse the ll upto n/2 then we'll start checking 
         
        int idx = 0;    
        int cnt = 0;
        ListNode* fast = head,*slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            s[idx++] = slow->val;
            fast = fast->next->next;
            slow = slow->next;
            cnt += 2;
        }
        if(fast != nullptr) cnt++;
        idx--; //goes to N/2 + 1 
        if(cnt&1) slow = slow->next;
        cout << cnt << endl;
        cout << idx << endl;
        while(slow!= nullptr) {
            if(s[idx] != slow->val) return false;
            slow = slow->next;
            if(slow == nullptr) break;
            --idx;
        }
        return true;
    }
};