class Solution:
    def rowWithMax1s(self, arr):
        # code here
        l=[]
        for i in arr:
            l.append(i.count(1))
        return l.index(max(l))