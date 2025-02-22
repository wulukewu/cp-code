import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())

a = 0
for i in range(len(str(n))):
    if int(str(n)[i]) >= 7: b = int(str(n)[i]) - 1
    else: b = int(str(n)[i])
    a += 9 ** (len(str(n)) - i - 1) * b
print(a)

c = (n-7) // 8 + 1
print(c)

