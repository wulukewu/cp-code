import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

arr = ['a', 'e', 'i', 'o', 'u']
w = input()

for i in w:
    if i not in arr:
        print(i, end = '')
print()