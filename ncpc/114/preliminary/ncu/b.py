hh, mm = map(int, input().split())

if 10<hh<15 or (hh==10 and mm>=30) or (hh==15 and mm<30):
	print('PRACTICE')
elif 7<=hh<23:
	print('AWAKE')
else:
	print('ASLEEP')
