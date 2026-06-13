/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
alignas(Node) static char memory_pool[1003*sizeof(Node)];  
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        int idx = 0;
        const auto& alloc = [&](int val) {
            Node* temp = new (&memory_pool[idx * sizeof(Node)]) Node(val);
            idx++;
            return temp;
        };
        unordered_map<Node*,Node*> mp;
        Node* node = head;
        Node* curr_head = alloc(node->val);
        mp[node] = curr_head;
        //first round we will just copy the next pointers and then we'll save the node pointers
        //in the second node we will copy that 
        node = node->next;
        Node* prev = curr_head;

        while(node!= nullptr) {
            Node* nxt = alloc(node->val);
            mp[node] = nxt;

            prev->next = nxt;
            prev = nxt;
            
            node = node->next;
        }

        node = head;
        prev = curr_head; //reusing variables
        while(node != nullptr) {
            if(node->random)
                prev->random = mp[node->random];
            prev = prev->next;
            node = node->next;
        }

        return curr_head;
    }
};

