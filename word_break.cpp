struct node {
    char data;
    unordered_map<char,node*> child;
    bool eof;
    node(char c) {
        data = c;
        eof = false;
    }
    node() : eof(false) {}
};
class trie {
public: 
    node* root = new node('*');
    void insert(string &s,int ind,node* curr) {
        if(ind == s.length()) {
            curr->eof = true;
            return;
        }

        if(curr->child.find(s[ind]) == curr->child.end()) {
            node* n1 = new node(s[ind]);
            curr->child[s[ind]] = n1;
        }
        // if(ind == s.length() - 1) {
        //     curr->child[s[ind]]
        // }
        insert(s,ind + 1,curr->child[s[ind]]);
    }
    void insert(string &s) {
        insert(s,0,root);
    }
};

class Solution {
    int dp[301];
    bool solve(string &s, trie &t1, int ind, node* curr) {
        if (ind == s.length()) {
            return curr->eof;
        }
        if (curr == t1.root && dp[ind] != -1) return dp[ind];

        // Check if current char exists as a child
        if (curr->child.find(s[ind]) == curr->child.end()) {
            // Dead end in trie — but if curr is eof, try restarting from root
            if (curr->eof && t1.root->child.find(s[ind]) != t1.root->child.end()) {
                return solve(s, t1, ind, t1.root); // restart from root at same ind
            }
            return false;
        }

        node* next = curr->child[s[ind]];
        bool res = solve(s, t1, ind + 1, next); // continue current word

        if (!res && curr->eof) {
            res = solve(s, t1, ind, t1.root); // break here, restart from root
        }
        if(curr == t1.root) dp[ind] = res;
        return res;
    }
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        trie* t1 = new trie();
        for(auto &x: wordDict) {
            t1->insert(x);
        }
        memset(dp,-1,sizeof(dp));
        //now we have to backtrack and check if we can form 
        return solve(s,*t1,0,t1->root);
        
    }
};
