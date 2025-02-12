from typing import List

class Solution:
    def twoSum(self, arr: List[int], t: int) -> List[int]:
        size = len(arr)
        
        # Create a list of tuples (element, original index) to track the original indices
        indexed_arr = [(num, idx) for idx, num in enumerate(arr)]
        
        # Sort the array based on the element values
        sorted_arr = sorted(indexed_arr, key=lambda x: x[0])
        
        i = 0
        j = size - 1
        
        while i < j:
            current_sum = sorted_arr[i][0] + sorted_arr[j][0]
            if current_sum == t:
                # Return the original indices of the two elements
                return [sorted_arr[i][1], sorted_arr[j][1]]
            elif current_sum > t:
                j -= 1
            else:
                i += 1
        
        # If no pair found, return an empty list
        return []
        

# Example of using the solution
solution = Solution()
arr = [2, 7, 11, 15]
target = 9
print(solution.twoSum(arr, target))  # Output: [0, 1]
