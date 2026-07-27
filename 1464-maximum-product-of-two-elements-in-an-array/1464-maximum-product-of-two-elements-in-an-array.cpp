class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 0, second = 0;
        for (int x : nums) {
            if (x >= mx) {
                second = mx;
                mx = x;
            } else if (x > second) {
                second = x;
            }
        }
        return (mx - 1) * (second - 1);
    }
};