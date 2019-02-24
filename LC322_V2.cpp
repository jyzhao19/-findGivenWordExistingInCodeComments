class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ordered_coins = coins;
        sort(ordered_coins.rbegin(), ordered_coins.rend());
        dfs(amount, 0, 0);
        return res<INT_MAX?res:-1;
    }
private:
    void dfs(int am, int cur, int n_coins) {
        //cout << am << " " << cur << " " << n_coins << endl;
        const int coin = ordered_coins[cur];
        if (am%coin==0) {
            res = min(res, n_coins+am/coin);
            return;
        }
        for(int k=am/coin; k>=0&&cur+1<ordered_coins.size()&&n_coins+k<res; k--) {
            dfs(am-k*coin, cur+1, n_coins+k);
        }
    }
    vector<int> ordered_coins;
    int res{INT_MAX};
};
