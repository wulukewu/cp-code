import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

w, b = map(int, input().split())

t = 'wbwbw'
for _ in range(10):
    t += t

W, B = 0, 0
s = []
for i in range(1000):
    if t[i] == 'w': W += 1
    else: B += 1
    s.append([W, B])
print(s)