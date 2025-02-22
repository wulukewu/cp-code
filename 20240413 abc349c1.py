import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
t = input().lower()
a = -1

det = True
for i in t:
    if i == 'x':
        continue

    if i in s:
        b = s.index(i)
        if b > a:
            a = b
            continue
        else:
            det = False
            break
    else:
        det = False
        break

if det:
    print('Yes')
else:
    print('No')