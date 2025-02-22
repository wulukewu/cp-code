import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
S = []; Ps = []
for i in range(N):
    S.append(input())
    for j in range(N):
        if S[i][j] == 'P':
            Ps.append((i, j))
(x1, y1) = Ps[0]
(x2, y2) = Ps[1]

dir = [0] # [上右下左]
def dfs(a, x1, y1, x2, y2):

    print(a, x1, y1, x2, y2, dir)
    if a == 100 or x1 < 0 or y1 < 0 or x2 < 0 or y2 < 0: return 100

    b = 0

    if x1 == x2 and y1 == y2:
        return a

    # 上
    if dir[-1] != 3:
        try:
            if S[x1-1][y1] == '.': x1_ = x1-1
            else: x1_ = x1
        except: return 100
        try:
            if S[x2-1][y2] == '.': x2_ = x2-1
            else: x2_ = x2
        except: return 100
        dir.append(1)
        b = min(b, dfs(b, x1_, y1, x2_, y2))
        dir.pop(-1)

    # 右
    if dir[-1] != 2:
        try:
            if S[x1][y1+1] == '.': y1_ = y1+1
            else: y1_ = y1
        except: return 100
        try:
            if S[x2][y2+1] == '.': y2_ = y2+1
            else: y2_ = y2
        except: return 100
        dir.append(2)
        b = min(b, dfs(b, x1, y1_, x2, y2_))
        dir.pop(-1)

    # 下
    if dir[-1] != 1:
        try:
            if S[x1+1][y1] == '.': x1_ = x1+1
            else: x1_ = x1
        except: return 100
        try:
            if S[x2+1][y2] == '.': x2_ = x2+1
            else: x2_ = x2
        except: return 100
        dir.append(3)
        b = min(b, dfs(b, x1_, y1, x2_, y2))
        dir.pop(-1)

    # 左
    if dir[-1] != 6:
        try:
            if S[x1][y1-1] == '.': y1_ = y1-1
            else: y1_ = y1
        except: return 100
        try:
            if S[x2][y2-1] == '.': y2_ = y2-1
            else: y2_ = y2
        except: return 100
        dir.append(4)
        b = min(b, dfs(b, x1, y1_, x2, y2_))
        dir.pop(-1)

    return a + b




print(dfs(0, x1, y1, x2, y2))