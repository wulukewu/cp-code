import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, a, b = map(int, input().split())
D = list(map(int, input().split()))
arr = []

for i in D:
    arr.append(i%(a+b))

# print(arr)
m1 = max(arr)
m2 = min(arr)
if m1 - m2 < a:
    print('Yes')
else:
    print('No')