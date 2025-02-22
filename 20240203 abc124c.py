import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

S = input()

# 0101
a = 0
for i in range(len(S)):
    if i % 2 == 0:
        j = '0'
    else:
        j = '1'
    
    if S[i] != j:
        a += 1

# 1010
b = 0
for i in range(len(S)):
    if i % 2 == 0:
        j = '1'
    else:
        j = '0'
    
    if S[i] != j:
        b += 1

ans = min(a, b)
print(ans)