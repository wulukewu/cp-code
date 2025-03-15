import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

s = 0
for i in range(2*n-2):
    if A[i] == A[i+2]:
        s += 1
        
print(s)