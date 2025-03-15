import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
cond = True

for i in range(len(s)):
    if i == 0:
        if s[i] == '<': next
        else: 
            cond = False
            break
    
    if s[i-1] == '<' or s[i-1] == '=':
        if s[i] == '<':
            cond = False
            break
    else:
        if s[i] == '=' or s[i] == '>':
            cond = False
            break

if cond:
    print('Yes')
else:
    print('No')