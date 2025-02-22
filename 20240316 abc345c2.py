import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()

def check(i):
    char = []
    char_num = []
    for i in s[i:]:
        if i in char:
            j = char.index(i)
            char_num[j] += 1
        else:
            char.append(i)
            char_num.append(1)
    return char, char_num    


char, char_num = check(0)
if sum(char_num) == len(char_num):
    x = 0
else:
    x = 1

for i in range(len(s)):
    if i != len(s) - 1:
        char, char_num = check(i+1)
        n = sum(char_num)       
        if s[i] in char:
            m = char_num[char.index(s[i])]
        else:
            m = 0
        x += n - m

print(x)