class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n;; x++) {
            long long prod = 1;
            int y = x;
            while (y > 0) {
                prod *= (y % 10);
                y /= 10;
                if (prod == 0) break;
            }
            if (prod % t == 0) return x;
        }
        return -1;
    }
};