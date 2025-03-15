import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
s = 0
for i in range(1, n+1):
    a = '7' not in str(i) 
    
    b = True
    while i > 1:
        if '7' in str(i % 8):
            b = False
            break
        i //= 8
    
    if a and b:
        s += 1
print(s)