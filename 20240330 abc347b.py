import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()

arr = []
n = 0
for i in range(len(s)):
    for j in range(i+1, len(s)+1):
        # print(i, j, s[i:j])
        if s[i:j] not in arr:
            arr.append(s[i:j])
            n += 1
# print(n, arr)
print(n)