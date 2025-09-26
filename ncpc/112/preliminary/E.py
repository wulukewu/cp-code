import math

def check(x, y):
    return abs(x-y) < 10**(-10)

t = int(input())
l = int(input())

m = 1+3+9+27+81+243
xrr = [0]*m
yrr = [0]*m
lrr = [0]*m
drr = [0]*m

xrr[1] = 0
yrr[1] = 0
lrr[1] = l
drr[1] = 0

idx = 1
for i in range(1, 4+1):
    for j in range(pow(3, i)):
        d = 0
        for k in [-1, 0, 1]:
            new = idx*3+k
            lrr[new] = lrr[idx] / 2
            drr[new] = drr[idx] + 30 + d
            drr[new] %= 360
            xrr[new] = xrr[idx] + lrr[idx] * math.cos(drr[new]*math.pi/180)
            yrr[new] = yrr[idx] + lrr[idx] * math.sin(drr[new]*math.pi/180)
            d += 120
            d %= 360
        idx += 1
# print(xrr)
# print(yrr)
# print(lrr)
# print(drr)

for _ in range(t):
    i1, i2, i3 = map(int, input().split())
    x1 = xrr[i1]
    x2 = xrr[i2]
    x3 = xrr[i3]
    y1 = yrr[i1]
    y2 = yrr[i2]
    y3 = yrr[i3]
    # print(x1, y1, x2, y2, x3, y3)

    # if (y2-y1)*(x3-x2) == (y3-y2)*(x2-x1):
    if check((y2-y1)*(x3-x2), (y3-y2)*(x2-x1)):
        print('Null')
        continue

    ab = (x1-x2)**2 + (y1-y2)**2
    bc = (x2-x3)**2 + (y2-y3)**2
    ac = (x1-x3)**2 + (y1-y3)**2
    # print(ab, bc, ac)

    c, b, a = sorted([ab, bc, ac])
    # print(a, b, c)
    if check(a, b) and check(b, c):
    # if a==b and b==c:
        print('Equilateral')
    elif check(a, b) or check(b, c):
    # elif a==b or b==c:
        print('Isosceles')
    elif check(a, b+c):
    # elif a == b + c:
        print('Right')
    elif a < b + c:
        print('Acute')
    elif a > b + c:
        print('Obtuse')
