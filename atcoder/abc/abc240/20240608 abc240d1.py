import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def strange_balls(N, a):
    stack = []
    result = []

    for i in range(N):
        ball = a[i]
        if stack and stack[-1][0] == ball:
            stack[-1][1] += 1
        else:
            stack.append([ball, 1])
        
        if stack[-1][1] == ball:
            stack.pop()
        
        result.append(sum(count for _, count in stack))
    
    return result

import sys
input = sys.stdin.read
data = input().split()
N = int(data[0])
a = list(map(int, data[1:]))

output = strange_balls(N, a)
for count in output:
    print(count)