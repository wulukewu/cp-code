import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
t = input().lower()

det = False
j = 0
for i in range(len(s)):    
    if j == 3 or (j == 2 and t[2] == 'x'):
        det = True
        break

    if s[i] == t[j]:
        j += 1

if j == 3 or (j == 2 and t[2] == 'x'):
    det = True

if det:
    print('Yes')
else:
    print('No')