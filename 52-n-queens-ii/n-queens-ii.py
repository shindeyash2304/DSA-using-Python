class Solution:
    def totalNQueens(self, n: int) -> int:
        cols = set()
        posDiag = set()  # r + c
        negDiag = set()  # r - c
        count = 0

        def backtrack(r):
            nonlocal count
            if r == n:
                count += 1
                return

            for c in range(n):
                if c in cols or (r + c) in posDiag or (r - c) in negDiag:
                    continue

                cols.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)

                backtrack(r + 1)

                # backtrack
                cols.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)

        backtrack(0)
        return count