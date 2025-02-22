import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
r = 10**len(str(n))
m = 998244353

# rn = r**n
rn = 1
R = r; N = n
M = m * (r-1)
while N > 1:
    # print(r, n, R, N, rn)
    if N%2 == 1:
        rn = rn*R%M
        N -= 1
    R = R**2%M
    N //= 2
rn = rn*R%M
# print(rn)

ans = (n%m) * (rn - 1) // (r-1)
ans %= m
print(ans)
