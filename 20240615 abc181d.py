import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
n = len(s)
arr = [0]*10
det = False

if n == 1:
    det = int(s) % 8 == 0
elif n == 2:
    det = int(s)%8==0 or int(s[1]+s[0])%8==0
else:
    for i in s:
        arr[int(i)]+=1
    # print(arr)

    for i in range(10):
        if arr[i] > 0:
            arr[i] -= 1
        else:
            continue

        for j in range(10):
            if arr[j] > 0:
                arr[j] -= 1
            else:
                continue

            for k in range(10):
                if arr[k] > 0:
                    arr[k] -= 1
                else:
                    continue

                if (100*i+10*j+1*k) % 8 == 0:
                    det = True
                    break
                arr[k] += 1
            arr[j] += 1
            if det: break
        arr[i] += 1
        if det: break

if det:
    print('Yes')
else:
    print('No')