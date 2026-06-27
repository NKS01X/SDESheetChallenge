class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        int nxtSmallest[n], prevSmallest[n];
        stack<int> minSt;
        for(int i = 0;i < n; ++i) { 
            while(!minSt.empty() && height[minSt.top()] >= height[i]) minSt.pop();
            prevSmallest[i] = minSt.empty() ? -1 : minSt.top();
            minSt.push(i);
        }
        while(!minSt.empty()) minSt.pop();
        for(int i = n - 1;i >= 0; --i) { 
            while(!minSt.empty() && height[minSt.top()] >= height[i]) minSt.pop();      
            nxtSmallest[i] = minSt.empty() ? n : minSt.top();
            minSt.push(i);
        }
        int ans = 0;
        for(int i = 0;i < n; ++i) {
            int lo = prevSmallest[i] + 1, hi = nxtSmallest[i] - 1;
            int range = (hi - lo + 1);
            int area = range*height[i];
            ans = max(area,ans);
        }
        return ans;
    }
};
