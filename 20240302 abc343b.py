import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
for _ in range(n):
    a = list(map(int, input().split()))
    for i in range(n):
        if a[i] == 1:
            print(i + 1, end=' ')
    print()