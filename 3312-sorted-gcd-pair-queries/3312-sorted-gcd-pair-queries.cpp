class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(mx + 1, 0);

        for (int x : nums) cnt[x]++;

        vector<long long> divCount(mx + 1, 0);
        for (int g = 1; g <= mx; ++g) {
            for (int m = g; m <= mx; m += g) {
                divCount[g] += cnt[m];
            }
        }

        vector<long long> exact(mx + 1, 0);
        for (int g = mx; g >= 1; --g) {
            long long pairs = divCount[g] * (divCount[g] - 1) / 2;
            for (int m = 2 * g; m <= mx; m += g) {
                pairs -= exact[m];
            }
            exact[g] = pairs;
        }

        vector<long long> pref(mx + 1, 0);
        for (int g = 1; g <= mx; ++g) pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (pref[mid] > q) r = mid;
                else l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};