import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

B = []
for i in range(n-1):
    B.append(str(A[i]*A[i+1]))

ans = ' '.join(B)
print(ans)