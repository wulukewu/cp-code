import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

W, B = map(int, input().split())

a = min(W // 7, B // 5)
W -= a * 7
B -= a * 5

det = False
t = 'wbwbwwbwbwbwwbwbwwbwbwbw'

if W == 0 and B == 0:
    det = True
else:
    for i in range(len(t)):
        for j in range(i, len(t)):
            # print(t[i:j])
            w, b = 0, 0
            for k in t[i:j]:
                if k == 'w': w += 1
                else: b += 1
            if W == w and B == b:
                det = True
                break

if det:
    print('Yes')
else:
    print('No')