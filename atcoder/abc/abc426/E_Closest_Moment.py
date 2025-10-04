q = int(input())

def dis(x, y):
    return (x**2 + y**2) ** (1/2)

for qq in range(q):
    tsx, tsy, tgx, tgy = map(int, input().split())
    asx, asy, agx, agy = map(int, input().split())
    
    def loc_t(t):
        total_t = dis(tsx-tgx, tsy-tgy)
        if t >= total_t:
            return tgx, tgy
        else:
            tx = tsx + (tgx-tsx)*t/total_t
            ty = tsy + (tgy-tsy)*t/total_t
            return tx, ty
    def loc_a(t):
        total_t = dis(asx-agx, asy-agy)
        if t >= total_t:
            return agx, agy
        else:
            ax = asx + (agx-asx)*t/total_t
            ay = asy + (agy-asy)*t/total_t
            return ax, ay
    
    def d(t):
        tx, ty = loc_t(t)
        ax, ay = loc_a(t)
        return dis(tx-ax, ty-ay)

    l = 0
    r = max(dis(tsx-tgx, tsy-tgy), dis(asx-agx, asy-agy))
    # ans = 4e4

    for i in range(150):
        m1 = l + (r-l) / 3
        m2 = r - (r-l) / 3

        d1 = d(m1)
        d2 = d(m2)

        if d1 < d2:
            r = m2
        else:
            l = m1

        # mid = l + (r-l) / 2
        # d1 = d(mid)
        # d2 = d(mid + 1e-10)
        # if d1<d2:
        #     r = mid
        # else:
        #     l = mid
        # ans = min(ans, d1, d2)

    print(f'{d(l):.15f}')