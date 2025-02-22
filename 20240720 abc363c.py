import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
s = input()

arr = {}
for i in s:
    if i in arr:
        arr[i] += 1
    else:
        arr[i] = 1

print(arr)