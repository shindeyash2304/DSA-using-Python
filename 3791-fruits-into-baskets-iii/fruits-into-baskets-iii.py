import math
from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        sect_mx = []
        m = len(baskets)
        a = int(math.sqrt(m))  # size of one array

        cnt = 0
        mx = 0
        for i in range(m):
            if cnt == a:
                # creating sector of size a
                sect_mx.append(mx)
                mx = baskets[i]
                cnt = 1
            else:
                cnt += 1
                mx = max(mx, baskets[i])

        # last sector
        sect_mx.append(mx)

        remain = 0

        # start allocating
        for fruit in fruits:
            k = 0
            set_flag = 1

            for j in range(0, m, a):
                if sect_mx[k] < fruit:
                    # skip this segment
                    k += 1
                    continue

                # find place to allocate
                for r in range(j, min(j + a, m)):
                    if baskets[r] >= fruit:
                        set_flag = 0
                        baskets[r] = 0
                        break

                # if fruit is allocated in a sector
                if set_flag == 0:
                    sect_mx[k] = 0  # find new mx
                    # update new sector mx
                    for r in range(j, min(j + a, m)):
                        sect_mx[k] = max(baskets[r], sect_mx[k])
                    break

                k += 1

            remain += set_flag

        return remain