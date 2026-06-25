class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        stack<int> st1;
        while(!st.empty()) {
            int t = st.top(); 
            st.pop();
            int cnt = 0;
            while(!st1.empty() && st1.top() < t) {
                ++cnt;
                st.push(st1.top());
                st1.pop();
            }
            st1.push(t);
            for(int i = 0;i < cnt; ++i) {
                st1.push(st.top());st.pop();
            }
        }
        while(!st1.empty()) {
            st.push(st1.top());st1.pop();
        }
    }
};

