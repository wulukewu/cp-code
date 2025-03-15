import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
arr = [-1] * N

def f(x):
    if x == 0:
        return 1
    else:
        a = int(x/2)
        b = int(x/3)

        if arr[a] > 0:
            A = arr[a]
        else:
            A = f(a)
            arr[a] = A
        
        if arr[b] > 0:
            B = arr[b]
        else:
            B = f(b)
            arr[b] = B

        return A + B

print(f(N))