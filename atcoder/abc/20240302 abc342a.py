import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()

for i in range(len(s)-2):
    a = s[i]
    b = s[i+1]
    c = s[i+2]

    if a == b:
        if b == c:
            next
        else:
            # print(c)
            print(i+3)
            break
    else:
        if a == c:
            # print(b)
            print(i+2)
            break
        else:
            # print(a)
            print(i+1)
            break