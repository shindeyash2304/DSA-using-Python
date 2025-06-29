class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        MOD = 10 ** 9 + 7
        nums = [num for num in nums if num < target]
        nums.sort()
        n = len(nums)
        left, right = 0, n - 1
        res = 0
        while left <= right:
            if nums[left] + nums[right] > target:
                right -= 1
            else:
                size = right - left  # ignore the number at left
                res = (res + pow(2, size, MOD)) % MOD   # nC0 + nC1 + nC2 + ... + nCn
                left += 1
        return res