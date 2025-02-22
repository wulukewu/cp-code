import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())

S = []; C = []
for _ in range(n):
    s, c = input().split()
    S.append(s)
    C.append(int(c))

ss = S.copy()
ss.sort()

a = sum(C)
a %= n
b = ss[a]
print(b)