import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, w = map(int, input().split())
print(n//w)