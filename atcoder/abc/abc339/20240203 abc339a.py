import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

S = list(input().split('.'))

print(S[-1])