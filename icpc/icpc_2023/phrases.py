N = int(input())


def subroutine(keyword, lis, memo={}):
    if keyword == "":
        return 1

    if keyword in memo:
        return memo[keyword]

    count = 0
    for i in range(len(keyword) + 1):
        first_part = keyword[:i]
        second_part = keyword[i:]

        if first_part in lis:
            count += subroutine(second_part, lis, memo)

    memo[keyword] = count
    return memo[keyword]


for i in range(N):
    lis = set(input().split(","))  # set is correct
    keyword = input()
    print(subroutine(keyword, lis))
