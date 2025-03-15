import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m, k = map(int, input().split())
C = []; A = []; R = []

for _ in range(m):
    arr = list(input().split())
    C.append(arr[0])
    A.append(arr[1:-2])
    R.append(arr[-1])
print(C, A, R)