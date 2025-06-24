class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        valid = [0] * (n + 1)  
        for i, val in enumerate(nums):
            if val == key:
                start = max(0, i - k)
                end = min(n, i + k + 1)
                valid[start] += 1
                valid[end] -= 1

        result = []
        count = 0
        for i in range(n):
            count += valid[i]
            if count > 0:
                result.append(i)

        return result