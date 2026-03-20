class Solution:
    def findPreSuc(self, root, key):
        ret=[None,None]
        def dfs(cur=root):
            nonlocal key
            if not cur or ret[0]!=None and ret[1]!=None:
                return
            dfs(cur.left)
            if cur.data<key:
                ret[0]=cur
            elif ret[1]==None and cur.data>key:
                ret[1]=cur
            dfs(cur.right)
        dfs()
        return ret