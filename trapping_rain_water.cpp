class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> mxStack;
        int ans = 0;
        int n = height.size();

        for (int i = 0; i < n; ++i) {
            while (!mxStack.empty() && height[i] > height[mxStack.top()]) {
                int bottom = mxStack.top();
                mxStack.pop();
                
                if (mxStack.empty()) break;
                
                int nxtgreater = mxStack.top();
                int range = i - nxtgreater - 1;
                int mn = min(height[i], height[nxtgreater]);
                
                ans += range * (mn - height[bottom]);
            }
            mxStack.push(i);
        }
        
        return ans;
    }
};
