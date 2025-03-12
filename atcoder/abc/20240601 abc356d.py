import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())

def popcount(a_, b_):
    a = str(format(a_, 'b'))
    b = str(format(b_, 'b'))
    n = min(len(a), len(b))
    # print(a_, b_, a, b, n)

    s = 0
    for i in range(1, n+1):
        # print(a[(-1)*i], b[(-1)*i])
        if a[(-1)*i]=='1' and b[(-1)*i]=='1':
            s += 1
    
    return s

m2 = format(m, "b")
l = len(m2)
n_ = 2**l-1
# print(m2, l, n_)

count1 = 0
for i in m2:
    if i == '1':
        count1 += 1

ans = count1 * 2**(l-1)
# print(ans)

if n > n_:
    s = 0
    for i in range(n_+1, n+1):
        # print(f'i:{i}')
        s += popcount(i, m)
    ans += s
elif n == n_:
    pass
else:
    s = 0
    for i in range(n+1, n_+1):
        # print(f'i:{i}')
        s += popcount(i, m)
    ans -= s

ans %= 998244353
print(ans)
