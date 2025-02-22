import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

x, y = map(int, input().split())
print(max(x, y))