import math

n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=True)

a = arr[m-1]
b = arr[m]
# print(a, b)
v = (a + b) / 2
total = m * v

e = total / n
pay = v - e

# print(pay, e)
p = math.floor(pay)
q = math.ceil(e)
# print(p, q)


r = abs(m * p - (n-m)*q)
print(p, q, r)