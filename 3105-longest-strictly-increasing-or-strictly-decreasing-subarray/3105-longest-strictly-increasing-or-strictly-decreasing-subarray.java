class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length, iCnt = 1, dCnt = 1, ans = 1;

        for(int i = 1; i < n; i++){
            if(nums[i - 1] < nums[i]) iCnt++;
            else iCnt = 1;

            if(nums[i - 1] > nums[i]) dCnt++;
            else dCnt = 1;

            ans = Math.max(ans, Math.max(iCnt, dCnt));
        }
        return ans;
    }
}