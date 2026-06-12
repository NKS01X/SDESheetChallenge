class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode* cur = head;

        while(cur != nullptr) {
            if(seen.count(cur)) {
                return cur; 
            }
            seen.insert(cur);
            cur = cur->next;
        }
        return nullptr; 
    }
};
