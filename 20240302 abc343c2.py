import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

a = [1, 8, 343, 1331, 1030301, 1367631, 1003003001, 10662526601, 1000300030001, 1030607060301, 1334996994331, 1000030000300001, 1033394994933301, 1331399339931331]
n = int(input())
b = 0

for i in range(13):
    if a[i + 1] > n:
        print(a[i])
        b = 1
        break

if b == 0:
    print(a[13])
