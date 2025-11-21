import heapq

class Solution:
    def shortestPath(self, V, a, b, edges):
        adj = [[] for _ in range(V)]
        curved = []
        for x, y, w1, w2 in edges:
            adj[x].append((y, w1))
            adj[y].append((x, w1))
            curved.append((x, y, w2))

        def dijkstra(src):
            dist = [10**18] * V
            dist[src] = 0
            pq = [(0, src)]
            while pq:
                d, u = heapq.heappop(pq)
                if d != dist[u]:
                    continue
                for v, w in adj[u]:
                    nd = d + w
                    if nd < dist[v]:
                        dist[v] = nd
                        heapq.heappush(pq, (nd, v))
            return dist

        da = dijkstra(a)
        db = dijkstra(b)

        ans = da[b]
        for x, y, w2 in curved:
            v1 = da[x] + w2 + db[y]
            if v1 < ans:
                ans = v1
            v2 = da[y] + w2 + db[x]
            if v2 < ans:
                ans = v2

        return -1 if ans >= 10**18 else ans