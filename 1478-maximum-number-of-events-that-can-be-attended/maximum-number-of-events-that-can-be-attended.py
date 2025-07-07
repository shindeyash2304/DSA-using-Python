class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()  # Sort by start day
        n = len(events)
        hp = []  # Min-heap to store end days of available events
        day = 1
        i = 0
        attended = 0

        while i < n or hp:
            # Add all events that start on the current day
            while i < n and events[i][0] == day:
                heappush(hp, events[i][1])
                i += 1
            
            # Remove all events that have already ended
            while hp and hp[0] < day:
                heappop(hp)

            # Attend the event that ends the soonest
            if hp:
                heappop(hp)
                attended += 1

            day += 1
        
        return attended