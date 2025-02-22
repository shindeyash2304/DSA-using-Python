class Solution:
    def maxLength(self, S: str) -> int:
        n = len(S)
        open = close = 0
        ans = 0

        # Left to Right
        for i in range(n):
            if S[i] == '(':
                open += 1
            else:
                close += 1

            if open == close:
                ans = max(ans, open * 2)
            elif close > open:
                open = close = 0

        # Right to Left
        open = close = 0
        for i in range(n - 1, -1, -1):
            if S[i] == '(':
                open += 1
            else:
                close += 1

            if open == close:
                ans = max(ans, open * 2)
            elif open > close:
                open = close = 0

        return ans

#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.maxLength(S))
        print("~")

# } Driver Code Ends