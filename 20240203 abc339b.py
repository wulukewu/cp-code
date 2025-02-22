import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

H, W, N = map(int, input().split())

arr = [['.'] * W for _ in range(H)]

i = 0; j = 0
dir = 0 # [上右下左]
for _ in range(N):
    
    if arr[i][j] == '.':
        arr[i][j] = '#'
        dir = (dir + 1) % 4
    else:
        arr[i][j] = '.'
        dir = (dir - 1) % 4

    if dir == 0: #上
        i = (i-1+H) % H
    elif dir == 1: #右
        j = (j+1+W) % W
    elif dir == 2: #下
        i = (i+1+H) % H
    else: #左
        j = (j-1+W) % W

for t in arr:
    print(''.join(t))