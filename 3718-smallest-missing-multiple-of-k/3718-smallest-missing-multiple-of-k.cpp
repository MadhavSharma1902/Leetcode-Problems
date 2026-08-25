class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int x = k;
        while (true) {
            if (!s.count(x)) return x;
            x += k;
        }
    }
};