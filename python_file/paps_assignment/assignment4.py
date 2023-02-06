# print('This program check if the number is Armstrong or not.')
# print('Enter the number.')
# # n=(input('> '))
# n='371'
# digit_list=list(n)
# def sq(x):
#     return int(x)**2
# def sumer(x):
#     sum=0
#     for i in x:
#         sum+=int(i)
#     return sum
# for i in digit_list:
#     sum=0
#     sum+=int(i)
# check_list=list(map(sq,digit_list))
# if sumer(check_list)==sum:
#     print('It is a Armstrong Number.')
# else:
#     print('It is not a Armstrong Number.')
emp_data=[]
class Employe:
    

    def __init__(self,name,designation,gender,doj,salary) -> None:
        self.name=name
        self.designation=designation
        self.gender=gender
        self.doj=doj
        self.salary=salary
        self.emp_data.append(self)
    
    def print_emp(self):
        print(emp_data)
sahil=Employe(sahil,ceo,m,232,9999999)
Employe.print_emp()