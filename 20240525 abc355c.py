import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, t = map(int, input().split())
A = list(map(int, input().split()))

# arr = [[0] * n for _ in range(n)] 
arr1 = [0] * n
arr2 = [0] * n
arr3 = 0
arr4 = 0

ans = -1
for i in range(t):
    x = A[i] // n
    y = A[i] % n

    if y == 0:
        x -= 1
        y = n - 1
    else:
        y -= 1
    # print(x, y)
    
    arr1[x] += 1
    arr2[y] += 1
    if arr1[x] == n or arr2[y] == n:
        ans = i + 1
        break

    if x == y:
        arr3 += 1
        if arr3 == n:
            ans = i + 1
            break
    
    if x + y + 1 == n:
        arr4 += 1
        if arr4 == n:
            ans = i + 1
            break

print(ans)