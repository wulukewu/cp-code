input_list = []
while True:
    try:
        inp = input()
        if inp == '-'*75:

            name = input_list[0]
            unit = input_list[1]

            ab = []
            if len(input_list) == 3:
                line = input_list[2]
                a = -1
                b = -1
                if ',' in line:
                    a_half, b_half = line.split(',')
                    if '[' in a_half:
                        a = map(int, a_half.split('['))[-1]
                    else:
                        a = map(int, a_half.split('['))[-1] + 1
                    if ']' in b_half:
                        b = map(int, b_half.split('['))[-1]
                    else:
                        b = map(int, b_half.split('['))[-1] - 1
                elif '~' in line:
                    a, b = map(int, line.split('~'))
                elif '<=' in line:
                    b = map(int, line.split('<='))[-1]
                elif '<' in line:
                    b = map(int, line.split('<'))[-1] - 1
                elif '>=' in line:
                    a = map(int, line.split('>='))[-1]
                elif '>' in line:
                    a = map(int, line.split('>'))[-1] + 1
                print(a, b)
            else:
                pass

            input_list = []
            continue
        elif inp == '='*80:
            break
        input_list.append(inp.strip())
    except: break

print(input_list)

# i = 0
# while i<len(input_list):

#     line = input_list[i]


#     i += 1
    
# while True:
#     a = input()
#     if a=='='*80:
#         break
#     test_name = a
#     unit = input()

#     tabl = []
#     while True:
#         rang = input()
#         if rang=='-'*75:
#             break
#         lab = input()
#         if lab=='-'*75:
#             l = -1
#             r = -1
#             if '<=' in rang:
#                 a = rang.split('<=')[-1]
#                 print(a)
#             break
#         else:
#             pass
