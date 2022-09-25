emp_data=[]

class Emp():
    def __init__(self,name,designation,gender,doj,salary) -> None:
        self.name=name
        self.designation=designation
        self.gender=gender
        self.doj=doj
        self.salary=salary
        emp_data.append(self)

    def emp_count():
        return len(emp_data)

    def emp_gender():
        male_count=0
        female_count=0
        for i in emp_data:
            if i.gender=='M':
                male_count+=1
            elif i.gender=='F':
                female_count+=1
        print(f'Male: {male_count} Female: {female_count}')
    
    def emp_salary():
        emp_salary=[]
        for i in emp_data:
            if i.salary>=10000:
                emp_salary.append(i.name)
        return emp_salary

    def emp_designation():
        emp_design=[]
        for i in emp_data:
            if i.designation=='Asst Manager':
                emp_design.append(i.name)
        return emp_design

e1=Emp('Sangam','CEO','M',2,99999)
e2=Emp('Harsh','Asst Manager','F',6,666666)
e3=Emp('Soumya','Asst Manager','M',898,8876)

print(f'Total Emp are: {Emp.emp_count()}')
print()
Emp.emp_gender()
print()
print('Emp with salary greater than 10K are: ')
for index,i in enumerate(Emp.emp_salary()):
    print(str(index+1)+'.',i)
print()
print('Emp with desgination Asst Manager.')
for i in Emp.emp_designation():
    print(str(index+1)+'.', i)

