import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N, K = map(int, input().split())
P = list(map(int, input().split()))
arr = [-1] * N

for i in range(len(P)):
    arr[P[i]-1] = i

# print(arr)

c = 9999999
for i in range(N-K+1):
    a = i; b = i + K
    d = max(arr[a:b]) - min(arr[a:b])
    # print(arr[a:b+1], d)
    c = min(c, d)
    
    if c == 1:
        break

print(c)