import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

def dfs():
    global arr
    global case
    for i in A:
        for j in range(m):
            if i > B[j] and arr[j] == 0:
                A.remove(i)
                arr[j] = i
                # print(i, j, A, B, arr)

                det = True
                for k in arr:
                    if k == 0:
                        det = False
                        break
                if det: 
                    case.append(sum(arr))
                    # print(f'A: {A}, arr: {arr}, sum: {sum(arr)}')
                    A.append(i)
                    # B[j] = 0
                    arr[j] = 0
                    break
                else:
                    dfs()
                    A.append(i)
                    # B[j] = 0
                    arr[j] = 0

arr = [0] * m
case = []
dfs()
# print(case)
print(min(case))