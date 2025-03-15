import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

H, W = map(int, input().split())
# s = [[0] * W for _ in range(H)]
s = [[0 for _ in range(W)] for _ in range(H)]
black_num = 0
for i in range(H):
    arr = str(input())
    for j in range(W):
        if arr[j] == '#':
            s[i][j] = 1
            black_num += 1

# print(black_num, s)

todo = [(0, 0)]
s[0][0] = 1

while len(todo) > 0:
# for i in range(10):
    i = todo[0][0]
    j = todo[0][1]

    # Up
    if i - 1 >= 0:
        if s[i-1][j] == 0:
            todo.append((i-1, j))
            s[i-1][j] = s[i][j] + 1

    # Right
    if j + 1 < W:
        if s[i][j+1] == 0:
            todo.append((i, j+1))
            s[i][j+1] = s[i][j] + 1

    # Down
    if i + 1 < H:
        if s[i+1][j] == 0:
            todo.append((i+1, j))
            s[i+1][j] = s[i][j] + 1

    # Left
    if j - 1 >= 0:
        if s[i][j-1] == 0:
            todo.append((i, j-1))
            s[i][j-1] = s[i][j] + 1

    # print(todo)
    todo.pop(0)

# print(s)

if s[H-1][W-1] == 0:
    print(-1)
else:
    ans = H * W - s[H-1][W-1] - black_num
    print(ans)