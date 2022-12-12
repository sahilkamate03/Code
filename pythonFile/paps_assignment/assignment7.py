print('''
This is a basic calculator. It can perform following task:
1. Add
2. Subtract
3. Multiplication
4. Division
5. Power 
6. Factorial
''')
x=5
y=6

def calc(x,y,z):
    if z==1:
        return x+y
    elif z==2:
        return x-y
    elif z==3:
        return x*y
    elif z==4:
        return x/y
    elif z==5:
        return x**y

def fact(x):
    if x==0:
        return 1
    else:
        return x*fact(x-1)



# 
while True:
    print('Enter the task you want to do.')
    feed=int(input('> '))

    if 1<=feed<6 :
        print('Enter First Number.')
        x=int(input('> '))
        print('Enter Second Number.')
        y=int(input('> '))
        print(f'Result: {calc(x,y,feed)}')
    elif feed==6:
        print('Enter the number.')
        n=int(input('> '))
        print(f'Result: {fact(n)}')
    else: 
        break