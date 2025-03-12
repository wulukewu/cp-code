import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

arr = []
while True:
    a = int(input())
    arr.append(a)
    if a == 0:
        break

N = len(arr)
for i in range(N):
    print(arr[N-1-i])