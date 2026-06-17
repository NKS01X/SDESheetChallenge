class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i][j] denotes min number of coins needed to make i amount with first j elements of coin
        const int n = coins.size();
        int dp[n + 1][amount + 1];
        const int INF = 1e9;
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= amount; ++j)
                dp[i][j] = INF;

        //can i make 0 with any indices ? fuck ys
        for(int i = 0; i <= n; ++i) 
            dp[i][0] = 0;

        for(int i = 1;i <= n; ++i) {
            for(int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j]; // ya toh pehle se hi possible ho?? 

                if(j - coins[i - 1] >= 0) 
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1); //ya coins[i - 1] se banade
            }        
        }

        return dp[n][amount] == INF ? -1 : dp[n][amount];
        

    }
};

