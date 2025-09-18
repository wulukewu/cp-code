import math

t = int(input())
for tt in range(t):
    arr = list(map(int, input().split()))
    brr = list(map(int, input().split()))
    v = [arr, brr]
    # print(v)

    ans = False
    for i in range(2):
        for j in range(2):
            for k in range(2):
                x1 = v[i][0]
                y1 = v[i][1]
                x2 = v[j][2]
                y2 = v[j][3]
                x3 = v[k][4]
                y3 = v[k][5]
                print(x1, y1, x2, y2, x3, y3)

                ux = x1 - x2
                uy = y1 - y2
                vx = x3 - x2
                vy = y3 - y2
                # print(ux, uy, vx, vy)
                if (ux==0 and uy==0) or (vx==0 and vy==0): continue

                uv = ux * vx + uy * vy
                ul = ux**2 + uy**2
                ull = math.sqrt(ul)
                vl = vx**2 + vy**2
                vll = math.sqrt(vl)
                # print(uv, ull, vll)
                cos = uv / ull / vll
                print(cos)

                if i==0 and j==0 and k==0:
                    ans_cos = cos
                elif cos==ans_cos and [x1, y1, x2, y2, x3, y3]!=v[0]:
                    ans = True
                    break
            if ans: break
        if ans: break
    
    if ans:
        print('Yes')
    else:
        print('No')
    
    print()