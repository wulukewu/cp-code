import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
a = 0

i = 0
while i < n:
    if A[i] % 2 == 0:
        A[i] //= 2
        a += 1
        i -= 1
    i += 1

print(a)