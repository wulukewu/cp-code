n = int(input())
s = str(input())

case = -1
ans = ""
for i in s:
	if(case == -1):
		if(i == "1" or i == "l"):
			ans = "1"
			case = 0
		else:
			ans = "0"
			case = 1
	elif(case == 0):
		if(i == "0" or i == "O"):
			ans = ans + "0"
			case = 1
	elif(case == 1):
		if(i == "1" or i == "l"):
			ans = ans + "1"
			case = 0
print(ans)
