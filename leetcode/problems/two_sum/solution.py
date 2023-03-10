class Solution:
    def twoSum(self, nums: List[int], t: int) -> List[int]:
        idx = {}
        for i, n in enumerate(nums):
            j = idx.get(t-n)
            if j is not None:
                return [j, i]
            idx[n] = i
        return []