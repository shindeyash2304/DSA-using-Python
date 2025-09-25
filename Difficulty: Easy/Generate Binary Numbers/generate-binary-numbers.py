class Solution:
    def generateBinary(self, n):
        q = deque(["1"])
        res = []
        for _ in range(n):
            cur = q.popleft()
            res.append(cur)
            q.append(cur + "0")
            q.append(cur + "1")
        return res

