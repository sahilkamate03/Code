# def func1(n):
#     def exe():
#         print('executing')
#         n()
#         print('executes')
#     return exe
# @func1 
# def hello():
#     print("hello")
#     # for i in range(5):
#     #     print(i)
#     #     return hello
# hello()

# # func1(hello)
# # hell()

class emp:
    leaves=8
    def __init__(dell,aname,asalary, arole):
        dell.name=aname
        dell.salary=asalary
        dell.role=arole

    @classmethod
    def change_leaves(cls, new_leaves):
        cls.leaves=new_leaves

    @classmethod
    def from_str(cls, stri):
        p=stri.split('-')
        return cls(p[0],p[1],p[2])
    
    @staticmethod
    def printer(string):
        print("this is a printer "+string)

class pro(emp):
    def print_pro(self):
        return f"Pro name is {self.name}. Salary is {self.salary}, Role is {self.role}"
    
    # pass

sahil=pro("sahil",10000,"CEO")
harshal=emp('harshal',1000,"manager")

print(sahil.print_pro())
# sahil.change_leaves(200000)
# karan=emp.from_str("karan-30-watchman")
# print(karan.role)
# s=0
# sahil.printer('sahil kamate')
# print(sahil.leaves)
# print(harshal.leaves)
# print(sahil.name)
# # print(emp.leaves)
# emp.leaves=0
# print(emp.leaves)