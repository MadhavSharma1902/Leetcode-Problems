class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int sum1 = 0, sum2 = 0, q1 = 0, q2 = 0;

        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') q1++;
            else sum1 += num[i] - '0';
        }

        for (int i = half; i < n; ++i) {
            if (num[i] == '?') q2++;
            else sum2 += num[i] - '0';
        }

        int diff = sum1 - sum2;
        int qdiff = q2 - q1;

        return diff * 2 != qdiff * 9;
    }
};