import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
S = input()
Q = int(input())

for _ in range(Q):
    a, b = input().split()
    S.replace(a, b)

print(S)