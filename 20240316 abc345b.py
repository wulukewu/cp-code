import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

x = int(input())

while x % 10 != 0:
    x += 1

y = int(x//10)
print(y)