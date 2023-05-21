import sys
arguments = sys.argv
print(arguments[1])
flag = arguments[1]
result = ''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)]) 
print(result)
