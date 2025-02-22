import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
S = []

for _ in range(n):
    S.append(input())

def f():
    global arr1
    global arr2
    global ans
    for i in range(n):
        if arr1[i] == 1:
            continue
        else:
            arr1_ = arr1.copy()
            arr2_ = arr2.copy()
            arr1[i] = 1
            for k in range(m):
                if S[i][k] == 'o':
                    arr2[k] = 1
            # print(arr1, arr2)

            if arr2 == [1]*m:
                a = 0
                for i in arr1:
                    if i == 1: a += 1
                ans = a
                break
            elif arr1 == [1]*n:
                ans = n
                break

            f()
            # arr1[i] = 0
            arr1 = arr1_.copy()
            arr2 = arr2_.copy()
    if arr2 == [1]*m:
        a = 0
        for i in arr1:
            if i == 1: a += 1
        ans = a
    elif arr1 == [1]*n:
        ans = n


arr1 = [0]*n
arr2 = [0]*m
ans = -1

f()
print(ans)
# print(arr1, arr2)