t = int(input())

for _ in range(t):
    xl, yl, xr, yr = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    # print(a, b, c, d, e, f, g, h)

    ans = False
    if (xl <= x1 <= xr and yl <= y1 <= yr) or (xl <= x2 <= xr and yl <= y2 <= yr):
        ans = True
    else:
        if x2-x1==0:
            if max(y1, y2) >= yr and min(y1, y2) <= yl and xl <= x1 <= xr:
                ans = True
            else:
                ans = False
            # if xl <= x2 <= xr and (yl <= y1 <= yr or yl <= y2 <= yr):
            #     ans = True
            # else:
            #     ans = False
            # ans = False
        elif y2-y1==0:
            if max(x1, x2) >= xr and min(x1, x2) <= xl and yl <= y1 <= yr:
                ans = True
            else:
                ans = False
            # if yl <= y2 <= yr and (xl <= x1 <= xr or xl <= x2 <= xr):
            #     ans = True
            # else:
            #     ans = False
            # ans = False
        else:
            m = (y2-y1)/(x2-x1)
            k = (x2*y1-y2*x1)/(x2-x1)
            # print(m, k)

            def fy(x):
                return m * x + k
            def fx(y):
                return (y-k)/m

            for i in [yl, yr]:
                x = fx(i)
                # print(x)
                if xl <= x <= xr and min(x1, x2) <= x <= max(x1, x2):
                    ans = True
                    break
            for i in [xl, xr]:
                y = fy(i)
                # print(y)
                if yl <= y <= yr and min(y1, y2) <= y <= max(y1, y2):
                    ans = True
                    break


    if ans:
        print('STOP')
    else:
        print('OK')