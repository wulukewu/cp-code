mp = {}
# for i in range(1, 100):
for i in range(1, int(2e5)):
    p = int(i ** 2)
    # print(f'p: {p}')
    ps = str(p)
    n = len(ps)
    for j in range(n-1):
        a = ps[:j+1]
        b = ps[j+1:]
        # print(a, b)
        if b[0] == '0': continue
        a, b = map(int, [a, b])
        if a in mp:
            mp[a].append([b, p])
        else:
            mp[a] = [[b, p]]
# print(mp)

t = int(input())

for tt in range(t):
    c, d = map(int, input().split())
    if c in mp:
        ans = 0
        for i, j in mp[c]:
            # print(i, j)
            x = i - c
            if 0 <= x <= d:
                # print(f'x={x} p={j}')
                ans += 1
        print(ans)
    else:
        print(0)
    # print('---')