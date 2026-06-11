class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            ++len;
            temp = temp->next;
        }
        
        const auto& reverse_k = [&](ListNode* first) -> pair<ListNode*, ListNode*> {
            ListNode* prev = nullptr;
            ListNode* curr = first;
            
            for(int i = 0; i < k; ++i) {
                ListNode* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            
            first->next = curr; 
            
            return {prev, curr};      
        };

        int times = len / k; 
        ListNode* last = nullptr;
        ListNode* curr = head; 
        
        for(int i = 0; i < times; ++i) {
            ListNode* group_tail = curr; 
            auto [new_group_head, next_group_start] = reverse_k(curr);
            
            if(!last) {
                head = new_group_head;   
            } else {
                last->next = new_group_head; 
            }
            
            last = group_tail;          
            curr = next_group_start;
        }
        
        return head;
    }
};