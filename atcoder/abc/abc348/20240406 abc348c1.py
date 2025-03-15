import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = []
C = []
for _ in range(N):
    a, c = map(int, input().split())
    A.append(a)
    C.append(c)

aarr = []
carr = []
for i in range(N):
    try:
        idx = carr.index(C[i])
        aarr[idx] = min(aarr[idx], A[i])
    except:
        carr.append(C[i])
        aarr.append(A[i])
    # print(aarr, carr)

ans = max(aarr)
print(ans)