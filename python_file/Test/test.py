
x = int ( input ( ) )
v = list(map(int,input().split()))
for i in range(x):
    print(v[x-i-1], end=' ')
