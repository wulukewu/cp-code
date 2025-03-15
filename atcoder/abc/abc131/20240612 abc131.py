import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

arr = sorted(arr, key=lambda ab: ab[1])

t = 0
det = True
for i in arr:
    t += i[0]
    if t > i[1]:
        det = False
        break

if det:
    print('Yes')
else:
    print('No')