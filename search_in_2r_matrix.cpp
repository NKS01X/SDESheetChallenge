class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int tar) {
        int n = g.size();
        int m = g[0].size();
        //complexity of logm + logn = log(m*n)
        //func for bs in the row
        auto bsRow = [&](int i)->bool {
            int lo = 0,hi = m-1,mid;
            while(lo<=hi) {
                mid = (lo+hi)/2;
                if(g[i][mid] == tar) {
                    return true;
                }else if(g[i][mid] > tar) {
                    hi = mid-1;
                }else {
                    lo = mid+1;
                }
            }
            return false;
        };
        int low = 0,high = n-1,mid,idx = -1;
        while(low <= high) {
            mid = (low+high)/2;
            if(g[mid][m-1] == tar) {
                return true;
            }else {
                if(g[mid][m-1] > tar) {
                    idx = mid;
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }
        }
        if(idx == -1) return false;
        return bsRow(idx);
    }
};