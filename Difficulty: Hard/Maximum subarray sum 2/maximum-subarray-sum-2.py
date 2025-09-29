from collections import deque

class Solution:
    def maxSubarrSum(self, arr, a, b):
        n = len(arr)
        
        # Step 1: prefix sums
        prefix = [0] * (n+1)
        for i in range(n):
            prefix[i+1] = prefix[i] + arr[i]
        
        # Deque will store indices of prefix sums
        dq = deque()
        res = float('-inf')
        
        for r in range(a, n+1):  
            # Maintain left index range: [r-b, r-a]
            # Add prefix[r-a] into deque (candidate for subarray starting point)
            while dq and prefix[dq[-1]] >= prefix[r-a]:
                dq.pop()
            dq.append(r-a)
            
            # Remove invalid indices (smaller than r-b)
            while dq and dq[0] < r-b:
                dq.popleft()
            
            # Best candidate = prefix[dq[0]]
            res = max(res, prefix[r] - prefix[dq[0]])
        
        return res