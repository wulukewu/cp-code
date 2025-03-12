import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

arr = []
for _ in range(9):
    arr.append(input())

print(arr)