import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

H, W = map(int, input().split())
A = []
for i in range(H):
    A.append(list(input()))
    for j in range(W):
        if A[i][j] == 'S':
            si, sj = i, j
        # if A[i][j] == 'T':
        #     ti, tj = i, j

N = int(input())
E = [[0 for _ in range(W)] for _ in range(H)]
for _ in range(N):
    r, c, e = map(int, input().split())
    E[r-1][c-1] = e

goto = [(si, sj, 0)]

det = False

while len(goto) > 0:
    i = goto[0][0]
    j = goto[0][1]
    e = goto[0][2]
    print(i, j, e)

    if A[i][j] == 'T':
        det = True
        break

    for k in range(2):
        if E[i][j] > 0 and k == 1: 
            e = E[i][j]

        if i > 0:
            if A[i-1][j] == '.' and e > 0:
                goto.append((i-1, j, e-1))
        if i < H - 1:
            if A[i+1][j] == '.' and e > 0:
                goto.append((i+1, j, e-1))
        if j > 0:
            if A[i][j-1] == '.' and e > 0:
                goto.append((i, j-1, e-1))
        if j < W - 1:
            if A[i][j+1] == '.' and e > 0:
                goto.append((i, j+1, e-1))
    
    goto.pop(0)
    # print(goto)

if det:
    print('Yes')
else:
    print('No')