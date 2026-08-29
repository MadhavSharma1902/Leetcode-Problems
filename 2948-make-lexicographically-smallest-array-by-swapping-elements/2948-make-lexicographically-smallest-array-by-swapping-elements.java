class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        
        java.util.Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n - 1 && arr[j + 1][0] - arr[j][0] <= limit) j++;
            
            int[] values = new int[j - i + 1];
            int[] indices = new int[j - i + 1];
            
            for (int k = i; k <= j; k++) {
                values[k - i] = arr[k][0];
                indices[k - i] = arr[k][1];
            }
            
            java.util.Arrays.sort(indices);
            java.util.Arrays.sort(values);
            
            for (int k = 0; k < indices.length; k++) {
                nums[indices[k]] = values[k];
            }
            
            i = j + 1;
        }
        
        return nums;
    }
}