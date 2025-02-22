import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

r = int(input())
if r >= 100:
    r = int(str(r)[-2:])
print(100-r)
