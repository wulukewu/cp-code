import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())

if n >= m//2:
    ans = m//2
    n -= ans
    m -= ans*2

else:
    ans = n
    n = 0
    m -= ans*2

ans += m//4
m %= 4

print(ans)