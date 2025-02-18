#{ 
 # Driver Code Starts
#Initial Template for Python 3
from typing import List


# } Driver Code Ends

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Your code here
        for i in range(len(points)):
            #calculate square of distance from the origin
            dist = points[i][0] * points[i][0] + points[i][1] * points[i][1] 
            # append the square of distance from origin as third element to list for each point 
            points[i].append(dist)
        # sort the list w.r.t. square of distance from origin 
        points.sort(key=lambda x: x[2])

        # return first k points, priting of first two elements x,y is taken care of in the driver code itself
        return points[:k]
        

#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        k = int(input())
        n = int(input())
        points = []
        for _ in range(n):
            x, y = map(int, input().split())
            points.append([x, y])
        
        solution = Solution()
        ans = solution.kClosest(points, k)
        ans.sort()
        for point in ans:
            print(point[0], point[1])
        print("~")

# } Driver Code Ends