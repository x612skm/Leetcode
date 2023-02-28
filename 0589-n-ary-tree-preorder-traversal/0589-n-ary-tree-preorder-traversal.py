"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def helper(self, root: 'Node', ans: List[int]) -> None:
        if not root:
            return
        ans.append(root.val)
        for i in root.children:
            self.helper(i, ans)

    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        self.helper(root, ans)
        return ans
