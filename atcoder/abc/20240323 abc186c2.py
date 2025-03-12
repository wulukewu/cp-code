import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def base(n,x):
    ret=""
    while x!=0:
        ret = str(x%n) + ret
        x //= n
    return ret
N = int(input())
ans = 0
for i in range(1,N+1):
    str_i = list(str(i))
    str_8 = list(base(8,i))
    if not("7" in str_i) and not("7" in str_8):
        ans += 1

print(ans)