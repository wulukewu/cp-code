import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
Q = int(input())
query = []
for _ in range(Q):
    query.append(list(map(int, input().split())))

B = [0] * n
t = 0; s = 0

for q in query:
    if q[0] == 1:
        t += 1
        s = q[1]
    elif q[0] == 2:
        if B[q[1]-1] == t:
            A[q[1]-1] += q[2]
        else:
            A[q[1]-1] = q[2] + s
            B[q[1]-1] = t
    else:
        if B[q[1]-1] == t:
            a = A[q[1]-1]
        else:
            a = s
        print(a)