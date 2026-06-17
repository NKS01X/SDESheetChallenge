class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false)); 
        
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for(int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        const auto& rec = [&](auto &self, int start) -> void {
            if(start == n) {
                ans.push_back(temp);
                return;
            } 

            for(int end = start; end < n; ++end) {
                if(dp[start][end]) {
                    temp.push_back(s.substr(start, end - start + 1)); 
                    self(self, end + 1);
                    temp.pop_back(); 
                }
            }
        };
        
        rec(rec, 0);
        
        return ans;
    }
};
