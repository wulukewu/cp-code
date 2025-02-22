import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
b = (n-1)*(m-1)
print(b)