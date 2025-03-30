class Solution:
    def startStation(self, gas, cost):
        n=len(gas)
        total_gas, total_cost = sum(gas), sum(cost)
        if total_gas<total_cost:
            return -1
        start=0
        tank=0
        for i in range(n):
            tank+=gas[i]-cost[i]
            if tank<0:
                start=i+1
                tank=0
        return start


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        gas = list(map(int, input().strip().split()))
        cost = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.startStation(gas, cost)
        print(ans)
        print("~")

# } Driver Code Ends