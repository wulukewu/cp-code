import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

A.sort()
count = 1
for i in range(n-1):
    if A[i] != A[i+1]:
        count += 1

print(count)