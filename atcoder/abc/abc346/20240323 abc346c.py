import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
# print(A)

t = 0
u = -1
for i in A:
    if i == u:
        continue
    elif i <= k:
        u = i
        t += i
    else:
        break

# print(t)
s = k*(k+1)//2 - t
print(s)