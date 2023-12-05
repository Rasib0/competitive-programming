# make a trie graph
# do bfs on it, starting from where history ended


def get_input():
    import sys

    words = sys.stdin.read().splitlines()[1:]
    return words


class TrieNode:
    def __init__(self):
        self.children = {}
        self.numOfWordsEndingHere = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert_and_return_end_node(self, word: str):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.numOfWordsEndingHere += 1  # repeatation of words are allowed
        return cur

    def use_bfs_to_count_words_that_match_in_history(self, start_node: TrieNode):
        count = 0
        from collections import deque

        q = deque()
        q.append(start_node)

        while q:
            cur = q.popleft()
            for c in cur.children:
                q.append(cur.children[c])
            if cur.numOfWordsEndingHere > 0:
                count += cur.numOfWordsEndingHere

        return count


words = get_input()
Tri = Trie()

for w in words:
    node = Tri.insert_and_return_end_node(w)
    print(Tri.use_bfs_to_count_words_that_match_in_history(node) - 1)
