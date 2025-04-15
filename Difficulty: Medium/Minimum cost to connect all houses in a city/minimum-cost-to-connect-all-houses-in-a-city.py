import heapq
class Solution:
    def manhattanDist(self, a, b): return abs(a[0] - b[0]) + abs(a[1] - b[1])
        
    def minCost(self, houses):
        n = len(houses)
        inMST = [False] * n
        minDist = [float("inf")] * n
        totalCost = 0
        pq = []
        heapq.heappush(pq, (0, 0))  # (cost, node)
        while pq:
            cost, u = heapq.heappop(pq)
            if inMST[u]: continue
            totalCost += cost
            inMST[u] = True
    
            for v in range(n):
                if not inMST[v]:
                    dist = self.manhattanDist(houses[u], houses[v])
                    if dist < minDist[v]:
                        minDist[v] = dist
                        heapq.heappush(pq, (dist, v))
        return totalCost
#{ 
 # Driver Code Starts
#Initial Template for Python 3
#Position this line where user code will be pasted.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        edges = []

        for _ in range(n):
            temp = list(map(int, input().split()))
            edges.append(temp)

        obj = Solution()
        print(obj.minCost(edges))
        print("~")
# } Driver Code Ends