import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
b = len(s)-2
t = s[0] + str(b) + s[len(s)-1]
print(t)