import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())

arr = [[]]*7

k = 0
while k <=n:
# for _ in range(5):
    if k == 0:
        arr[k] = ['1']
        k += 1
        next
    
    nk = 3**k
    nk1 = 3**(k-1)
    listt = [[-1]*nk for _ in range(nk)]
    for i in range(nk):
        for j in range(nk):
            if (i+1>nk1 and i+1<=nk1*2) and (j+1>nk1 and j+1<=nk1*2):
                # print(k,i,j)
                listt[i][j] = 0
            else:
                i_ = i%nk1
                j_ = j%nk1
                listt[i][j] = arr[k-1][i_][j_]
                


    arr[k] = listt
    k += 1

    # print(arr)

for i in arr[n]:
    for j in i:
        if j == '1':
            print('#', end='')
        else:
            print('.', end='')
    print()