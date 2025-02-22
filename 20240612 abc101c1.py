import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))

m = min(A)
m_idx = A.index(m)
# print(m, m_idx)

left_count = m_idx
right_count = n - m_idx - 1
# print(left_count, right_count)

a = min(left_count, right_count)
b = max(left_count, right_count)

t = 0
t += a//(k-1)
a %= k-1
t += b//(k-1)
b %= k-1
# print(a, b, t)

# if a != 0: t += 1
# if b != 0: t += 1

if a == 0:
    if b == 0:
        pass
    else:
        t += 1
else:
    if b == 0:
        t += 1
    else:
        if (a+b) % (k-1) == 0:
            t += 1
        else:
            t += 2

print(t)