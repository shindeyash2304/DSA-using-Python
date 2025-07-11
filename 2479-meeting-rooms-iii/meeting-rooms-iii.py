class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        rooms = [0]*n
        heap = []
        available = list(range(n))
        heapq.heapify(available)

        for x in meetings:
            while heap and heap[0][0] <= x[0]:
                heapq.heappush(available, heapq.heappop(heap)[1])
            if available:
                room = heapq.heappop(available)
                rooms[room] += 1
                heapq.heappush(heap, (x[1], room))
            else:
                closest = heapq.heappop(heap)
                rooms[closest[1]] += 1
                heapq.heappush(heap, (closest[0]+(x[1]-x[0]), closest[1]))
        
        return rooms.index(max(rooms))