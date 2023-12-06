class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        name = ''.join([name, '$'])
        typed = ''.join([typed, '$'])
        i = 0
        j = 0
        while i < len(name) and j < len(typed):
            if name[i] == typed[j]:
                i+=1
                j+=1
            elif j != 0 and typed[j] == typed[j - 1]:
                j+=1
            else:
                return False
        return True

    def isLongPressedName_owais(self, name: str, typed: str) -> bool:
        i = 0
        j = 0
        while  j < len(typed):
            if i < len(name) and name[i] == typed[j]:
                i+=1
                j+=1
            elif j != 0 and typed[j] == typed[j - 1]:
                j+=1
            else:
                return False
        return j == len(name)




sol = Solution()

print(sol.isLongPressedName("alex", "aaleex")) # True
print(sol.isLongPressedName("saeed", "ssaaedd")) # False
