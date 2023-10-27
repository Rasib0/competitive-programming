subset = []
subsets = []

n = 3


def search(k):
    if (k == n + 1):
        subsets.append(subset[:])
    else:
        subset.append(k)
        search(k + 1)
        subset.pop()
        search(k + 1)


search(1)
print(subsets)

print("------------------------")


def generate_subsets(n, subset, subsets):
    if n == 0:
        subsets.append(subset)
    else:
        generate_subsets(n - 1, subset + [n], subsets)
        generate_subsets(n - 1, subset, subsets)


n = 3  # Change the value of n as needed
subset = []
subsets = []
generate_subsets(n, subset, subsets)
print(subsets)

# subsets
for i in range(1 << n):
    for j in range(n):
        if i & (1 << j):
            print(j + 1, end=" ")
