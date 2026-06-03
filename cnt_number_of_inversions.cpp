class Solution {
    unordered_map<int, int> mp;
    const int mod = 1e9 + 7;
    int memo[305][405];
    
    int fn(int idx, int inv) {
        if(idx < 0) return inv == 0 ? 1 : 0;
        if(memo[idx][inv] != -1) return memo[idx][inv];
        if(mp.count(idx) && mp[idx] != inv) return memo[idx][inv] = 0;
        
        long long sum = 0;
        for(int k = 0; k <= idx; ++k) {
            if(inv - k >= 0) {
                sum = (sum + fn(idx - 1, inv - k)) % mod; 
            }
        }
        
        return memo[idx][inv] = sum;
    }
    
public:
    int numberOfPermutations(int n, vector<vector<int>>& req) {
        for(auto &x: req) {
            mp[x[0]] = x[1]; 
        }
        memset(memo, -1, sizeof(memo)); 
        return fn(n - 1, mp[n - 1]);
    }
};