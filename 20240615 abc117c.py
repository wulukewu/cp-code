import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
X = list(map(int, input().split()))
X.sort()
# print(X)

a = X[-1] - X[0]

arr = []
for i in range(m-1):
    arr.append(X[i+1] - X[i])
arr.sort(reverse=True)
# print(arr)

b = sum(arr[:(n-1)])
print(a-b)