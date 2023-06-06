totalStudent =8
# marks =[0] *100
marks =[5, 0, 5, 9, 8, 9, 9, 0, 6]

def takeInput():
	print ("Total Students")
	global totalStudent
	totalStudent =int(input("> "))
	print ("Enter marks")
	
	for i in range(totalStudent):
		tempRoll = int(input("Roll no: "))
		tempMarks =int(input("Marks: "))
		marks[tempRoll] =tempMarks


def calcAvg():
	sum =0
	for i in range (totalStudent):
		sum +=marks[i]

	avg =sum/totalStudent

	return avg

def highestMarks():
	max =-1
	for i in range(totalStudent):
		if marks[i] > max :
			max =marks[i]

	return max

def lowestMarks():
	min =101
	for i in range (totalStudent):
		if marks[i] != 0 and marks[i] < min:
			min =marks[i]

	return min

def mostFrequent():
	marks.sort()
	count =0
	maxFreq =0
	maxFreqMarksIndex =0
	for i in range(1, totalStudent):
		if (marks[i-1] != marks[i]):
			count =0
			continue

		count +=1
		if  marks[i] != 0 and count > maxFreq :
			maxFreqMarksIndex =i
			maxFreq =count

	return marks[maxFreqMarksIndex]

def listAbsentStudent():
	print ("Absent Students: ", end='')
	for i in range (totalStudent):
		if marks[i] == 0:
			print(i, end=" ")

# takeInput()
print("Avg Marks: ", calcAvg())
print("Highest Marks: ", highestMarks())
print("Lowest Marks: ", lowestMarks())
print("Most Freqent Marks: ", mostFrequent())
listAbsentStudent()