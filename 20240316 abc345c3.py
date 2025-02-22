import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()

char = []
char_num = []
char_index = []

x = 0
for i in range(len(s)):
    # print(char, char_num, char_index)
    if i == 0:
        char.append(s[i])
        char_num.append(1)
        char_index.append([i])
        continue
    
    try:
        j = char.index(s[i])
        # print(i, s[i], j)
        char_num[j] += 1
        char_index[j].append(i)
        x += sum(char_num) - char_num[j]
    except:
        char.append(s[i])
        char_num.append(1)
        char_index.append([i])
        x += sum(char_num) - 1

if sum(char_num) != len(char_num):
    x += 1

print(x)