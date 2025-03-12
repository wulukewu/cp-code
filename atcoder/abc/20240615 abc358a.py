import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s, t = input().split()
if s == 'AtCoder' and t == 'Land':
    print('Yes')
else:
    print('No')