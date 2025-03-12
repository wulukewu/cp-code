import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, x, y, z = map(int, input().split())

if (z >= x and z <= y) or (z >= y and z <= x):
    print('Yes')
else:
    print('No')