import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
count = 0
for i in range(n):
    s = input()
    if s == 'Takahashi':
        count += 1

print(count)