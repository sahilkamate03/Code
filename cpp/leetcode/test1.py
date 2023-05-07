a =[3, 1, 2, 3, 4]
b =0
for i, c in enumerate(a):
	b ^=((i+1)^c)

print(b)
