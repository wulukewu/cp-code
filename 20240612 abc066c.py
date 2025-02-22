import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

arr_odd = []
arr_even = []

for i in range(n):
    if i % 2 == 1:
        arr_odd.append(A[i])
    else:
        arr_even.append(A[i])
# print(arr_odd, arr_even)

if n % 2 == 0:
    for i in range(len(arr_odd)):
        print(arr_odd[(-1)*(i+1)], end=' ')
    for i in range(len(arr_even)):
        print(arr_even[i], end=' ')
else:
    for i in range(len(arr_even)):
        print(arr_even[(-1)*(i+1)], end=' ')
    for i in range(len(arr_odd)):
        print(arr_odd[i], end=' ')