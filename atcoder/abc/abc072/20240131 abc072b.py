import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math
s = input()

for i in range(len(s)):
    if i % 2 == 0:
        print(s[i], end = '')