import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

a, b = map(int, input().split())
arr = [1, 2, 3]

if a == b:
    print(-1)
else:
    for i in arr:
        if i != a and i != b:
            print(i)
            break