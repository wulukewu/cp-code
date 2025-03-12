import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
A.sort()
# print(A)

def f(x, y):
    return (x + y) % 10**8

s = 0
for i in range(n):
    a = A[i]
    c = 0
    if a < 5 * 10**4:
        b = 10**8 - a
        if b > A[-1]:
            continue
        l = i
        r = n
        while r - l > 1:
            mid = (l + r) // 2
            if A[mid] > b:
                r = mid - 1
            elif A[mid] < b:
                l = mid + 1
            else:
                l = mid
                r = mid
                c = 1
        # print(l, r)
        s += r - l - c + 1
    else:
        m = n - i
        s += m * (m-1)//2
        break
    
# print(s)

# s = 0
# for i in range(n-1):
#     for j in range(i+1, n):
#         t = f(A[i],A[j])
#         print(i, j, t)
#         s += t
# print(s)

ans = sum(A)*(n-1) - s * 10**8

print(ans)