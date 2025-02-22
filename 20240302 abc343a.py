import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

a, b = map(int, input().split())
c = 0

while True:
    if c != a + b:
        print(c)
        break
    c += 1