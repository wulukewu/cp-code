import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
t = 0
arr = []

for i in A:
    arr.append(i)
    t += 1

    if arr[(-1)*i:] == [i]*i:
        t -= i
        del(arr[(-1)*i:])

    print(t)