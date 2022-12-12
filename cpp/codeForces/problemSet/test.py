import sys
file_path = r'D:\code\cpp\codeForces\problemSet\output.txt'
sys.stdout = open(file_path, "w")
print("{")
for i in range(10001):
	print(i**3, end=",")

print("};")