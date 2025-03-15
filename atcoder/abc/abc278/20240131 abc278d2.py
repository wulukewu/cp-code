import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = list(map(int, input().split()))
Q = int(input())
query = []
for _ in range(Q):
    query.append(list(map(int, input().split())))

x = -1
B = []

for i in range(Q):
    q = query[i]

    if q[0] == 1:
        x = q[1]
        B = []
    elif q[0] == 2:
        inB = False
        for j in range(len(B)):
            if B[j][0] == q[1]:
                inB = True
                break
        if inB:
            B[j][1] += q[2]
        else:
            if x == -1:
                c = A[q[1]-1] + q[2]
            else:
                c = x + q[2]
            B.append([q[1], c])
    else:
        inB = False
        for j in range(len(B)):
            if B[j][0] == q[1]:
                inB = True
                break
        if inB:
            print(B[j][1])
        else:
            if x == -1:
                c = A[q[1]-1]
            else:
                c = x
            print(c)
