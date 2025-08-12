class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        temp = (len(prices) + k) // (k + 1)
        return sum(prices[:temp]), sum(prices[-temp:])