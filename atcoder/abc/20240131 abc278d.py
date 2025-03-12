import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = list(map(int, input().split()))
Q = int(input())
query = []
for _ in range(Q):
    query.append(list(map(int, input().split())))

for i in range(Q):
    q = query[i]
    if q[0] == 1:
        A = [q[1]] * N
    elif q[0] == 2:
        A[q[1]-1] += q[2]
    else:
        print(A[q[1]-1])
    
    # print(A)