import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
arr = {}

def f(x):
    if x == 0:
        return 1
    else:
        a = int(x/2)
        b = int(x/3)

        if a in arr:
            A = arr[a]
        else:
            A = f(a)
            arr[a] = A
        
        if b in arr:
            B = arr[b]
        else:
            B = f(b)
            arr[b] = B

        return A + B

print(f(N))