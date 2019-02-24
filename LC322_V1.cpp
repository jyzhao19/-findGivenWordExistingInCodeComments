class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (const auto coin: coins) {
          for (int am=coin; am<amount+1; am++) {
            dp[am]=min(dp[am], dp[am-coin]+1);
          }
        }
        return dp[amount] < amount+1 ? dp[amount] : -1;
    }
};
