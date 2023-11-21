import sys
t = int(input())

lines = sys.stdin.read().splitlines()

for i in range(t):
    count = 0
    department = {}
    k = int(input()) # number of people to be sent for in training 
    _ = input()
    department_ids = map(int, input().split())

