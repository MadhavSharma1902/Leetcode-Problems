class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<int> flat;
        flat.reserve(total);

        for (auto &row : grid) {
            for (int x : row) flat.push_back(x);
        }

        vector<int> shifted(total);
        for (int i = 0; i < total; i++) {
            shifted[(i + k) % total] = flat[i];
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < total; i++) {
            ans[i / n][i % n] = shifted[i];
        }

        return ans;
    }
};