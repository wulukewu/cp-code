import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def f(x):
    if x == 0:
        return 1
    else:
        a = int(x/2)
        b = int(x/3)
        return f(a) + f(b)

N = int(input())

print(f(N))