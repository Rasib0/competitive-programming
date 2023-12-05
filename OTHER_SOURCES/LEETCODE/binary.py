def binary(s):
    ans = ""
    for i in range(len(s)):
        if s[i] == "0":
            ans += "1"
        else:
            ans += "0"
    return ans
