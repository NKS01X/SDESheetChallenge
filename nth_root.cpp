class Solution {
    long long q_power(long long base, int power) {
        long long res = 1;
        for(;power;power>>=1){
            if(power & 1) {
                res = 1ll * base * res;
            }
            base = 1ll * base * base;
        }
        
        return res;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l = 0, r = m;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(q_power(mid, n) == m) return mid;
            else if(q_power(mid,n) > m) r = mid-1;
            else l = mid+1;
        }
        
        return -1;
    }
};
