import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())

for i in range(n):
    if i%3 == 2:
        print('x', end='')
    else:
        print('o', end='')