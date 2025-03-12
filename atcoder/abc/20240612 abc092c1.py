import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

for i in range(n):
    s = 0
    last = 0
    for j in range(n):
        if i == j:
            continue
        # print(i, j)
        s += abs(last-A[j])
        last = A[j]
    s += abs(last-0)
    print(s)