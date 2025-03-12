import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))
L = int(input())
C = list(map(int, input().split()))
Q = int(input())
X = list(map(int, input().split()))

def find(arr, key):
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l + r) / 2)
        if arr[mid] < key:
            l = mid + 1
        elif arr[mid] > key:
            r = mid - 1
        else:
            return True
    return False

arr = []
for a in A:
    for b in B:
        for c in C:
            arr.append(a + b + c)
arr.sort()

for x in X:

    det = find(arr, x)
    if det:
        print('Yes')
    else:
        print('No')