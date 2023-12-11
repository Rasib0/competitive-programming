# convert O(n . m ) to O(n + m) using KMP algorithm


# haystack = "ABCDEF"
# needle = "XYZ"
# Brute force approach: match substrings O(n . m)
# when strings don't match then O(n) like in the example above
# --- better example ----
# haystack = "AAAXAAAX"
# needle = "AAAA"

# Longest Prefix Suffix: LPS
# - longest prefix that is also a suffix of that substring

# LPS is an array the size of the needle
# each index corresponds to the LPS of every single prefix of the needle
# string itself cannot be a prefix or suffix of itself

# needle = "AAAA"
# LPS = [0, 1, 2, 3]


class Solution:
    def strStr(self, haystack: str, needle: str):
        if needle == "":
            return 0
        lps = [0] * len(needle)
        prevLPS, i = 0, 1
        while i < len(needle):
            if needle[i] == needle[prevLPS]:
                lps[i] = prevLPS + 1
                prevLPS += 1
            else:
                if prevLPS == 0:
                    lps[i] = 0
                    i += 1
                else:
                    prevLPS = lps[prevLPS - 1]
                    continue
