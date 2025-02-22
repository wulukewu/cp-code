import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
a = list(map(int, input().split()))

a.sort(reverse=1)
s = 0
for i in range(len(a)):
    if i % 2 == 0:
        s += a[i]
    else:
        s -= a[i]

print(s)