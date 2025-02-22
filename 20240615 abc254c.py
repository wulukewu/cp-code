import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))
A_sort = sorted(A)
# print(A, A_sort)

arr = []
for i in range(n):
    if A[i] == A_sort[i]:
        arr.append(0)
    else:
        arr.append(1)
# print(arr)

det = True
for i in range(n-k):
    if arr[i] > 0:
        if arr[i+k] > 0:
            arr[i] = 0
            arr[i+k] = 0
        else:
            det = False
            break
# print(arr)

if det:
    print('Yes')
else:
    print('No')