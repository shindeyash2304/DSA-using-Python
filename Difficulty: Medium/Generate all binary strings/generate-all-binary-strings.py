class Solution:
    def binstr(self, n):
        # code here
        x=2**n
        ans=[]
        for i in range(0,x):
            ans.append(format(i,'b').zfill(n))
        return ans