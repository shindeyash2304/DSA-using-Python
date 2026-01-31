class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        low = 0
        high = n - 1
        min_letter = 'z'
        count = 0
        while low <= high:
            mid = (low + high) // 2
            if letters[mid] > target:
                min_letter = min(letters[mid], min_letter)
                high = mid - 1
                count = 1
            else:
                low = mid + 1
        if count == 0:
            return letters[0]
        return min_letter