class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9+7
        oddCount = 0
        evenCount = 1
        prefixSum = 0
        result = 0
        
        for num in arr:
            prefixSum += num
            if prefixSum % 2 == 1:
                result = (result + evenCount) % mod
                oddCount += 1
            else:
                result = (result + oddCount) % mod
                evenCount += 1
                
        return result        