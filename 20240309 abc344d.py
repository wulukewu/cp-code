import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

T = input()
N = int(input())

A = []
S = []
for _ in range(N):
    arr = list(input().split())
    A.append(int(arr[0]))
    S.append(arr[1:])

