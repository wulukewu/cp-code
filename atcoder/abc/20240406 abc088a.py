import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = int(input())

N %= 500
if N <= A:
    print('Yes')
else:
    print('No')