class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int maxG = 0;
        for (int x : nums) maxG = max(maxG, x);

        vector<vector<long long>> dp(maxG + 1, vector<long long>(maxG + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;
            for (int g1 = 0; g1 <= maxG; ++g1) {
                for (int g2 = 0; g2 <= maxG; ++g2) {
                    long long cur = dp[g1][g2];
                    if (!cur) continue;

                    int ng1 = std::gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                    int ng2 = std::gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= maxG; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        return (int)ans;
    }
};