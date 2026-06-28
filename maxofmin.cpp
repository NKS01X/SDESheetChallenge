class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        int v[n];
        stack<int>st;
        v[0] = -1;
        st.push(0);
        for(int i=1;i<n;++i){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) v[i] = -1;
            else v[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
    
        int nsi[n]; 
        nsi[n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;--i){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }
        
        vector<int>ans(n+1,0);
        
        for(int i=0;i<n;++i){
            int len = nsi[i]-v[i]-1;
            ans[len] = max(ans[len],arr[i]);
        }
        
        for(int i=n-1;i>=1;--i) ans[i] = max(ans[i],ans[i+1]);
        ans.erase(ans.begin());
        return ans;
    }
};
