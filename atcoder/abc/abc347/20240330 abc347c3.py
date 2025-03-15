import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, a, b = map(int, input().split())
D = list(map(int, input().split()))

arr1 = []
for i in D:
    n = i % (a + b)
    # if n > (a + b) // 2:
    #     n -= a + b
    arr1.append(n)

# print(arr1)
m1 = max(arr1)
m2 = min(arr1)
if m1 - m2 < a:
    print('Yes')
else:

    arr2 = []
    for i in D:
        n = i % (a + b)
        if n > (a + b) // 2:
            n -= a + b
        arr2.append(n)

    # print(arr2)
    m1 = max(arr2)
    m2 = min(arr2)
    if m1 - m2 < a:
        print('Yes')
    else:
        print('No')