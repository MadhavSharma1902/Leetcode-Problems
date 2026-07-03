class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int num = c - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[b][num]) {
                    return false;
                }

                row[i][num] = col[j][num] = box[b][num] = true;
            }
        }
        return true;
    }
};