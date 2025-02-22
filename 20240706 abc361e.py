import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = []
B = []
C = []
for _ in range(n-1):
    a, b, c = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)

def dfs(x):
    global s, went, arr
    print(x, went, arr)

    det = True
    for i in range(n):
        if arr[i] == 0:
            det = False
    if det:
        return 0

    for i in range(n-1):
        det = False
        # try: det = B[i] == went[-2] and went[-1] == went[-3]
        # except: det = False
        if A[i] == x and not det:
            det2 = arr[B[i]-1] == 0
            if det2: arr[B[i]-1] = 1
            went.append(B[i])
            s += C[i] + dfs(B[i])
            went.pop(-1)
            if det2: arr[B[i]-1] = 0

        det = False
        # try: det = A[i] != went[-2] and went[-1] != went[-3]
        # except: det = False
        if B[i] == x and not det:
            det2 = arr[A[i]-1] == 0
            if det2: arr[A[i]-1] = 1
            went.append(A[i])
            s += C[i] + dfs(A[i])
            went.pop(-1)
            if det2: arr[A[i]-1] = 0
    return 0

went = []
arr = [0] * n
s = 0
for x in range(1, n+1):
    print(dfs(x))
    # ans = min(ans, dfs(x))