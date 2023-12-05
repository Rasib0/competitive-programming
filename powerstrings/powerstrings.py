def get_input():
    import sys

    strings = sys.stdin.read().splitlines()[:-1]
    return strings


strings = get_input()
print(strings)
# we need to find the smallest prefix after which the string starts repeating itself
