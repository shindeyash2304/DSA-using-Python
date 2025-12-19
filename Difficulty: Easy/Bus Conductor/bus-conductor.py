class Solution:
    def findMoves(self, chairs, passengers):
        # code here
        chairs.sort()
        passengers.sort()
        ans = 0
        for i in range(len(chairs)):
            ans = ans + abs(passengers[i] - chairs[i])
        return ans