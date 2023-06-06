matrix =[]
matrix1 =[]
matrix2 =[]

def buildOneMatrix():
	print("Matrix")
	matrixRow =int(input("Row: "))
	matrixColumn =int(input("Column: "))	
	
	for i in range(matrixRow):
		row =list(map(int, input("> ").split()))
		while matrixColumn != len(row):
			print("Incorrect Column Input")
			row =list(map(int, input("> ").split()))
		matrix.append(row)
	print()

def buildTwoMatrix():
	print("Matrix1")
	matrix1Row =int(input("Row: "))
	matrix1Column =int(input("Column: "))	
	
	for i in range(matrix1Row):
		row =list(map(int, input("> ").split()))
		while matrix1Column != len(row):
			print("Incorrect Column Input")
			row =list(map(int, input("> ").split()))
		matrix1.append(row)
	
	print()

	print("Matrix2")
	matrix2Row =int(input("Row: "))
	matrix2Column =int(input("Column: "))

	for i in range(matrix2Row):
		row =list(map(int, input("> ").split()))
		while matrix2Column != len(row):
			print("Incorrect Column Input")
			row =list(map(int, input("> ").split()))
		matrix2.append(row)

	print()

def printMatix(matrix):
	row =len(matrix)
	column =len(matrix[0])

	for x in range(row):
		for y in range(column):
			print(matrix[x][y], end=' ')
		print()

def isUpperTriangular(matrix):
	row =len(matrix)
	column =len(matrix[0])
	if (row != column):
		return -1

	for x in range(row):
		for y in range(column):
			if (y<x and matrix[x][y] != 0):
				return False 

	return True

def trace(matrix, direction):
	row =len(matrix)
	column =len(matrix[0])

	if row != column :
		return -1

	trace =0
	if (direction == "ltr"):
		for i in range(row):
			trace +=matrix[i][i]

	elif (direction == "rtl"):
		for i in range(row):
			trace +=matrix[i][column-i-1]

	else:
		print("Invalid Direction")
		return -1

	return trace

def transpose(matrix):
	row =len(matrix)
	column =len(matrix[0])

	result =[]
	for i in range(column):
		result.append([0] *row)

	for x in range(row):
		for y in range(column):
			result[y][x] =matrix[x][y]

	return result

def multiplyMatrix(matrix1, matrix2):

	matrix1Row =len(matrix1)
	matrix1Column =len(matrix1[0])

	matrix2Row =len(matrix2)
	matrix2Column =len(matrix2[0])

	if matrix1Column != matrix2Row:
		return -1

	result =[]
	for i in range(matrix1Row):
		result.append([0] *matrix2Column)

	for x in range(matrix1Row):
		for y in range(matrix2Column):
			for i in range(matrix2Row):
				result [x][y] +=matrix1[x][i] *matrix2[i][y]

	return result

def saddlePoint(matrix):
	row =len(matrix)
	column =len(matrix[0])
	saddlePoint =-1
	for x in range(row):
		minElement =min(matrix[x])
		
		minElementIndex =0
		for i in range(column):
			if minElement==matrix[i]:
				minElementIndex =i
				break

		for x1 in range(row):
			temp =matrix[x1][minElementIndex]
			if temp > minElement:
				minElement =temp
				minElementIndex =x1

		if minElement == min(matrix[x1]):
			saddlePoint =minElement

	return saddlePoint

def main():
	# takeInput()	
	# buildTwoMatrix()
	# buildOneMatrix()

	matrix =[[1,2,3,],
			  [7,5,6],
			  [7,8,9]]
	# print(isUpperTriangular(matrix))
	# print(trace(matrix, "ltr"))
	# print(trace(matrix, "rtl"))
	# printMatix(transpose(matrix))
	print(saddlePoint(matrix))
	print(matrix[::-1])
	# result =multiplyMatrix(matrix1, matrix2)
	# printMatix(result)

if __name__ == "__main__":
	main()


# matrix1 =[[1,2,3,],
# 			  [4,5,6]]
	
# matrix2 =[[1,2],
# 		  [3,4],
# 	 	  [5,6]]