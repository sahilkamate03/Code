# t=int(input())
# v=['a','e','i','o','u']

# def check(s):
#     for i in s:
#         if i in v:
#             s.remove(i)
#             # pass
#     return ('.'+'.'.join(s))

# for i in range(t):
#     s=list(input().lower())
#     print(check(s))
    
s=list(input('> ').lower())
v=['a','e','i','o','u','y']
re=[]
for i in s:
    # print(i)
    if i in v:
        re.append(i)
        # s.remove(i)
        # pass
for i in re:
    s.remove(i)
print('.'+'.'.join(s))