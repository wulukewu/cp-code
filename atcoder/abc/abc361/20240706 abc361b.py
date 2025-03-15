import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

a, b, c, d, e, f = map(int, input().split())
g, h, i, j, k, l = map(int, input().split())

arr = [[a,d,g,j], [b,e,h,k], [c,f,i,l]]
det = True
for ar in arr:
    if abs(ar[0]-ar[1]) + abs(ar[2]-ar[3]) <= abs(max(ar)-min(ar)):
        det = False
        break

if det:
    print('Yes')
else:
    print('No')