class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.length();
        if (n <= 1) return s;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 1;
        int lastidx = 0;

        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                if(s[i] == s[j]) {
                    if (len == 2 || dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        if(len > ans) {
                            ans = len;
                            lastidx = i;
                        }
                    }
                }
            }
        }
        
        return s.substr(lastidx, ans);
    }
};
