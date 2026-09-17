class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, n + 1);
        int ans = n + 1, sum = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l];
                l++;
            }
            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && dp[l - 1] != n + 1) {
                    ans = Math.min(ans, dp[l - 1] + len);
                }
                dp[r] = len;
            }
            if (r > 0 && dp[r - 1] != n + 1) {
                dp[r] = Math.min(dp[r], dp[r - 1]);
            }
        }

        return ans != n + 1 ? ans : -1;
    }
}