n = int(input())

for _ in range(n):
	x = input()

	ans = 1
	crr = [x]
	# while True:
	for j in range(15):
		arr = {}
		for i in x:
			if i in arr:
				arr[i] += 1
			else:
				arr[i] = 1
			# # print(i)
			# if len(arr)>0 and arr[-1][0]==i:
			# 	arr[-1][1] += 1
			# else:
			# 	arr.append([i, 1])
		# print(arr)
		brr = [j for j in arr.keys()]
		brr.sort()
		# print(brr)
		y = ''
		# print(arr.items())
		for i in brr:
			# print(i)
			y += str(arr[i]) + i
		print(ans, y)
		# if y==x:
		if y in crr:
			break
		else:
			x = y
			ans += 1
			crr.append(x)
	print(ans)
