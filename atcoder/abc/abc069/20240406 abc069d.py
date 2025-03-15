import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))

arr = [[0 for _ in range(W)] for _ in range(H)]
idx = 0

for i in range(H):
    for j in range(W):
        if i%2 == 1:
            j = W-j-1
        
        if a[idx] == 0:
            idx += 1
        
        arr[i][j] = idx + 1
        a[idx] -= 1


for i in range(H):
    for j in range(W):
        print(arr[i][j], end=' ')
    print()