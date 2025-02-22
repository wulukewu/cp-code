import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = int(input()[3:])
if s < 350 and s > 0 and s != 316:
    print('Yes')
else:
    print('No')