# def binaryToDecimal(binary):
#     binary1 = binary
#     decimal, i, n = 0, 0, 0
#     while(binary != 0):
#         dec = binary % 10
#         decimal = decimal + dec * pow(2, i)
#         binary = binary//10
#         i += 1
#     return decimal 
# i=01111101
# print(chr(binaryToDecimal(int(i))))
# exit()
s = input('> ').split(' 0')


def binaryToDecimal(binary):
    binary1 = binary
    decimal, i, n = 0, 0, 0
    while(binary != 0):
        dec = binary % 10
        decimal = decimal + dec * pow(2, i)
        binary = binary//10
        i += 1
    return decimal   

# binaryToDecimal(1100001)
a=[]
for i in s:
    a.append(chr(binaryToDecimal(int(i))))

print(''.join(a))
