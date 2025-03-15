import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()

u = 0; l = 0
for i in s:
    if i.isupper():
        u += 1
    else:
        l += 1

if u > l:
    s = s.upper()
else:
    s = s.lower()

print(s)