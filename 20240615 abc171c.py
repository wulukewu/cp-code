import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
s = 'abcdefghijklmnopqrstuvwxyz'
ans = []

while True:
# for i in range(10):
    a = n // 26
    b = n % 26
    # print(a, b)

    if b == 0:
        a -= 1
        b = 26

    ans.append(s[b-1])

    if a == 0:
        break
    else:
        n = a

for i in range(len(ans)):
    print(ans[(-1)*(i+1)], end='')