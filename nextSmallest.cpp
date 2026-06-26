class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        vector<int> ans(n,-1);
        
        for(int i = n - 1;i >= 0; --i) {
            int x = arr[i];
            while(!st.empty() & x <= st.top()) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(x);
        }
        return ans;
    }
};
