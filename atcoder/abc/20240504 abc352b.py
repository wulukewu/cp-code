import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
t = input()

idx = 0
arr = []
for i in range(len(t)):
    if t[i] == s[idx]:
        arr.append(str(i + 1))
        idx += 1

st = ' '.join(arr)
print(st)