print('Enter the string.')
s=input('> ')

print(f'Length of the string: {len(s)}')
print()
print(f'Reverse of the string {s[::-1]}')
print()
print('Enter a string to compare')
f=input('>')
print()
if f==s:
    print('String are equal.')
else:
    print('String are not equal.')
print()
if s==s[::-1]:
    print('The string are palindrome.')
else: 
    print('The string arent palindrome.')
print()
print('Enter the string to check substring.')
r=input('> ')
print()
if r in s:
    print('It has the substring.')
else:
    print('It dont have the substring.')