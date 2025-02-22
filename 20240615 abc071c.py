import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
A.sort()
# print(A)

arr = {}

for i in range(n-1):
    if A[i] == A[i+1]:
        if A[i] in arr:
            arr[A[i]] += 1
        else:
            arr[A[i]] = 1
    i += 1

arr2 = sorted(arr)
# print(arr2)

if len(arr2) >= 2:
    if arr[arr2[-1]] >= 4:
        print(arr2[-1]**2)
    else:
        print(arr2[-1]*arr2[-2])
else:
    print(0)