class Solution {
    public int findNumbers(int[] nums) {
        var count = 0;
        for (int n : nums) {
            var len = String.valueOf(n).length();
            if (len % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}