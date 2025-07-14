class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        val = 0
        while head:
            val = (val << 1) | head.val
            head = head.next
        return val