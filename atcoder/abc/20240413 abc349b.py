import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
arr = {}

for i in s:
    if i in arr:
        arr[i] += 1
    else:
        arr[i] = 1

arri = [0] * 100
for i in arr:
    arri[arr[i]-1] += 1

det = True
for i in arri:
    if not(i==0 or i==2):
        det = False
        break

if det:
    print('Yes')
else:
    print('No')
