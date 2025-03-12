import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
Q = int(input())
query = []
for _ in range(Q):
    query.append(list(map(int, input().split())))


det = True
# s = 0
arr = []
for q in range(Q):
    if query[q][0] == 1:
        det = False
        s = query[q][1]
        arr = []
    elif query[q][0] == 2:
        arr.append((query[q][1], query[q][2]))
    else:
        if det:
            a = A[query[q][1]-1]
        else:
            a = s

        for j in arr:
            if j[0] == query[q][1]:
                a += j[1]
        print(a)