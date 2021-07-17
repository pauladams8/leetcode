class Solution {
    public int[] sortedSquares(int[] nums) {
        int i = 0, j = nums.length - 1;
        int[] result = new int[nums.length];
        for (int k = j; k >= 0; k--) {
            if (Math.abs(nums[j]) > Math.abs(nums[i])) {
                result[k] = nums[j] * nums[j];
                j--;
            } else {
                result[k] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
}