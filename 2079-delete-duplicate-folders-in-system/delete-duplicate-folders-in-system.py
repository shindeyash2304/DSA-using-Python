from typing import List
from collections import defaultdict

class TrieNode:
    def __init__(self, name=""):
        self.name = name
        self.children = {}
        self.deleted = False

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        # Step 1: Build Trie
        root = TrieNode()
        for path in paths:
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = TrieNode(folder)
                node = node.children[folder]
        
        # Step 2: Serialize subtrees
        sig_map = defaultdict(list)

        def serialize(node: TrieNode) -> str:
            if not node.children:
                return ""
            serials = []
            for name in sorted(node.children.keys()):
                child = node.children[name]
                serials.append(f"{name}({serialize(child)})")
            signature = ''.join(serials)
            sig_map[signature].append(node)
            return signature

        serialize(root)

        # Step 3: Mark duplicates
        for nodes in sig_map.values():
            if len(nodes) > 1:
                for node in nodes:
                    node.deleted = True

        # Step 4: Collect valid paths
        result = []

        def collect(node: TrieNode, path: List[str]):
            if node.deleted:
                return
            if path:
                result.append(path[:])
            for name in node.children:
                collect(node.children[name], path + [name])

        for name in root.children:
            collect(root.children[name], [name])
        
        return result