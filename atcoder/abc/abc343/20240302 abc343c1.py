import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math
n = int(input())
printed = False

while n > 0:
    print(n)

    det1 = False
    for i in range(1, n):
        if i ** 3 == n:
            det1 = True
            # print(det1)
            break
        if i ** 3 < n and (i + 1) ** 3 > n:
            det1 = False
            # print(det1)
            break

    det2 = True
    m = int(len(str(n)))
    # print(m)
    for i in range(int(m / 2)):
        if str(n)[i] != str(n)[m - 1 - i]:
            det2 = False
            break

    # print(det1, det2)

    if det1 and det2:
        print(n)
        printed = True
        break
    else:
        n -= 1

if not printed:
    print(1)