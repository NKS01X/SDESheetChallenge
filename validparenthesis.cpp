class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;
        const auto& isopp = [](char c)->char {
            if(c == '(') return c^1;
            else if(c == '[' || c == '{') return c^6;
            else return 0;
        };
        for(auto &x: s) {
            if(!st.empty() && isopp(st.top()) == x) st.pop();
            else st.push(x);
        }
        return st.size() == 0;
    }
};
