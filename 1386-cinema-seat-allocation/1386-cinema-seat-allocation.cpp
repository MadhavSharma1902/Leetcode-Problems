class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (auto &r : reservedSeats) {
            int row = r[0], seat = r[1];
            rows[row] |= 1 << (seat - 1);
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {
            bool left  = ((mask & ((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4))) == 0); // 2-5
            bool mid   = ((mask & ((1 << 3) | (1 << 4) | (1 << 5) | (1 << 6))) == 0); // 4-7
            bool right = ((mask & ((1 << 5) | (1 << 6) | (1 << 7) | (1 << 8))) == 0); // 6-9

            if (left && right) ans += 2;
            else if (left || mid || right) ans += 1;
        }

        return ans;
    }
};