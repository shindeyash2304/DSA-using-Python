class Solution:
    def simulate(self, nums: list[int], start: int, dir: int) -> bool:
        n = len(nums)
        a = nums.copy()
        curr = start
        while 0 <= curr < n:
            if a[curr] == 0:
                curr += dir 
            else:
                a[curr] -= 1  
                dir = -dir   
                curr += dir 
        return all(v == 0 for v in a)

    def countValidSelections(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            if nums[i] != 0:
                continue
            if self.simulate(nums, i, -1):
                ans += 1  
            if self.simulate(nums, i, +1):
                ans += 1 
        return ans