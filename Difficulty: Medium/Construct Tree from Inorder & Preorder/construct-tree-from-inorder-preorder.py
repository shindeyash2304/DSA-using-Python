class Solution:
    def buildTree(self, inorder, preorder):
        def search(inorder, l, r, val):
            for i in range(l, r + 1):
                if inorder[i] == val:
                    return i
            return -1

        def cal(inorder, preorder, l, r):
            nonlocal ind
            if l > r:
                return None

            ptr = Node(preorder[ind])
            ind += 1

            if l == r:
                ptr.left = None
                ptr.right = None
                return ptr

            inindex = search(inorder, l, r, ptr.data)
            ptr.left = cal(inorder, preorder, l, inindex - 1)
            ptr.right = cal(inorder, preorder, inindex + 1, r)

            return ptr

        ind = 0
        n = len(inorder)
        return cal(inorder, preorder, 0, n - 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3


class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        inorder = [int(x) for x in input().split()]
        preorder = [int(x) for x in input().split()]

        root = Solution().buildTree(inorder, preorder)
        printPostorder(root)
        print()

# } Driver Code Ends