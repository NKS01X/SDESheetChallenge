class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        dp[0].push_back(1);
        for(int i = 1;i < numRows; ++i) {
            for(int j = 0;j <= i; ++j) {
                //ek to straight upar 
                //aur ek thik leftone
                int right = 0;
                if(dp[i - 1].size() > j) 
                    right = dp[i - 1][j];
                int left = 0;
                if(j >= 1) 
                    left = dp[i - 1][j - 1];
                dp[i].push_back(left + right);
            }
        }
        return dp;
    }
};