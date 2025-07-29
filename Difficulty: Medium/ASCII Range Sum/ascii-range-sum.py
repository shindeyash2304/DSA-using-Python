from functools import reduce
class Solution:
    def asciirange(self, s):
        # code here
        l=[]
        nl=[]
        def adde(x1,y):
              if type(x1) is int:
                d=x1+ord(y)
              else:
                  d = ord(x1)+ord(y)
              return d
        for i in range(len(s)):
                x=[]
                if s[i] in nl:
                        continue
                else:
                    if s.count(s[i]) >1:
                        nl.append(s[i])
                        z=list(s[s.find(s[i])+1:s.rfind(s[i])])
                        if len(z)==1:
                            l.append(ord(z[0]))
                        elif len(z)!=0:
                            x = reduce(adde, z)
                            l.append(x)
        return l