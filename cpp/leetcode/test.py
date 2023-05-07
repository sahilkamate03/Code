a =[3, 1, 2, 4, 4]
n =5

suma =0
for i in a:
	print(i)
	suma +=i

expected =(len(a) * (len(a)-1))/2

print(suma)
print(expected)

print(suma-expected)