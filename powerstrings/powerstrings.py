def get_input():
    import sys

    strings = sys.stdin.read().splitlines()[:-1]
    return strings


strings = get_input()
print(strings)
