import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def prod(x):
    y = 1
    for i in range(x):
        y *= i + 1
    return y

s = input()

char = []
char_num = []

for i in s:
    if i in char:
        j = char.index(i)
        char_num[j] += 1
    else:
        char.append(i)
        char_num.append(1)

x = prod(sum(char_num))
for i in char_num:
    if i > 1:
        x //= prod(i)

# print(char, char_num)
print(x)