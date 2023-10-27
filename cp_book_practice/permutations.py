
subset = []
subsets = []

n = 3


def find_subsets(n):
    if n == 0:
        subsets.append(subset[:])
    else:
        subset.append(n)
        find_subsets(n - 1)
        subset.pop()
        find_subsets(n - 1)


find_subsets(3)
print(subsets)

permutation = []
permutations = []
choosen = [False] * (n + 1)


def find_permutations():
    if len(permutation) == n:
        permutations.append(permutation[:])
    else:
        for i in range(1, n + 1):
            if choosen[i]:
                continue
            choosen[i] = True
            permutation.append(i)
            find_permutations()
            choosen[i] = False
            permutation.pop()


find_permutations()
print(permutations)
