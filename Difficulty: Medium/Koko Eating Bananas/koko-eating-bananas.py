class Solution:
    def kokoEat(self, arr, k):
        def ok(mid):
            nonlocal arr,k
            sm=0
            for ve in arr:
                sm+=(ve+mid-1)//mid
                if sm>k:
                    return False
            return True
        left=1
        right=max(arr)
        while left<right:
            mid=left+(right-left)//2
            if not ok(mid):
                left=mid+1
            else:
                right=mid
        return left