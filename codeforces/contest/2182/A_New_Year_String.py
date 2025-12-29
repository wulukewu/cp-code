t = int(input())

for tt in range(t):
    n = int(input())
    s = input()
    a = 1 if '2026' in s else 0
    b = 1 if '2025' not in s else 0
    if  a+b>0:
        print(0)
    else:
        print(1)