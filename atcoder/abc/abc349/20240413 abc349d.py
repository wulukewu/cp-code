import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def div(x):
    if not (x == 1 or x == 0):
        return div(x//2) + 1
    else:
        return 0

def is2(x):
    if x % 2 == 0:
        return is2(x//2)
    elif x == 1:
        return True
    else:
        return False

L, R = map(int, input().split())

l_arr = []
r_arr = []

if not is2(R):
    a = R - 2 ** div(R)
    r = R
    R = 2 ** div(R)

    b = str(format(a, "b"))
    c = 0
    for i in range(len(b)):
        if b[i] == '1':
            l_arr.append(r - 2 ** c)
            r_arr.append(r)
            r -= 2 ** c
        c += 1

while R % 2 == 0 and R//2 >= L:
    l_arr.append(R//2)
    r_arr.append(R)
    R //= 2

# if L != R:
    

print(l_arr)
print(r_arr)