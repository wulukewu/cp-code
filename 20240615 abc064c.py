import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
arr = {'gray':0, 'brown':0, 'green':0, 'cyan':0, 'blue':0, 'yellow':0, 'orange':0, 'red':0}
other = 0

for i in A:
    if i < 400: arr['gray']+=1
    elif i < 800: arr['brown']+=1
    elif i < 1200: arr['green']+=1
    elif i < 1600: arr['cyan']+=1
    elif i < 2000: arr['blue']+=1
    elif i < 2400: arr['yellow']+=1
    elif i < 2800: arr['orange']+=1
    elif i < 3200: arr['red']+=1
    else: other+=1

m1 = 0
for i in arr:
    if arr[i] > 0: m1 += 1
if n - m1 >= other:
    m2 = m1 + other
else:
    m2 = n

if n == other:
    if other <= 9:
        print(1, other)
    else:
        print(1, 9)
else:
    print(m1, m2)