class Solution:
    def mergeArrays(self, nums1: list[list[int]], nums2: list[list[int]]) -> list[list[int]]:
        res = [] 
        n, m = len(nums1), len(nums2)
        i, j = 0, 0 # current id pointers for nums1, nums2
        while i < n and j < m: # break while loop when finished with either list
            if nums1[i][0] == nums2[j][0]:
                res.append([nums1[i][0], nums1[i][1] + nums2[j][1]]) # id matches, add sum
                i += 1 # both lists go to next index
                j += 1

            # add smallest [index, value] and go to next index for that list
            elif nums1[i][0] < nums2[j][0]:
                res.append(nums1[i])
                i += 1
            else:
                res.append(nums2[j])
                j += 1

        res.extend(nums1[i:]) # add rest of list if wasn't fully processed in while loop
        res.extend(nums2[j:])

        return res