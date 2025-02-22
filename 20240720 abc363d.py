import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def main(n):
    # n = int(input())
    print(n, end='\t')

    def f(x):
        if x == 1: return 10
        else: return 9 * 10**((x+1)//2-1)

    if n <= 10:
        print(n-1)
    else:
        num = 1
        while True:
            num1 = f(num)
            num2 = f(num+1)
            # print(num1, num2)
            n -= num1
            num += 1
            # print(num, n)
            if n - num1 < num2:
                break
        print(f'{n}\t{num}', end = '\t')

        if n <= 10:
            t = str(n)
            for i in range(len(str(n))-1, -1, -1):
                if num % 2 == 1 and i == len(str(n))-1: continue
                t += str(n)[i]
            print(t)
        else:
            num += 1
            arr = [str(int(str(n)[0]))]
            for i in str(n)[1:]:
                arr.append(str(int(i) if int(i)-1 >= 0 else 0))
            # print(arr)
            
            t = ''.join(arr)
            # print(t)
            for i in range(len(arr)-1, -1, -1):
                if num % 2 == 1 and i == len(arr)-1:
                    continue
                t += arr[i]

            print(t)

for i in range(1, 1000):
    main(i)
# main(21)