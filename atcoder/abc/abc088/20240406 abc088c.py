import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

c = []
for _ in range(3):
    c.append(list(map(int, input().split())))

for i in range(3):
    a = min(c[i])
    for j in range(3):
        c[i][j] -= a

for j in range(3):
    a = min(c[0][j], c[1][j], c[2][j])
    for i in range(3):
        c[i][j] -= a

det = True
for i in range(3):
    for j in range(3):
        if c[i][j] != 0:
            det = False
            break

if det:
    print('Yes')
else:
    print('No')