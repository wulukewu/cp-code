import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

H = int(input())

a = 1
b = 0
while a-1 <= H:
    a *= 2
    b += 1
    

print(b)