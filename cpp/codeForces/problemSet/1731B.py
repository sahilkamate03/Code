def getSum(n):
	sum =0
	sum += (n *(n+1) *(2*n +1)) / 6;
	n-=1;
	sum += (n *(n+1) *(n+2))/3;
	return sum;

t =int(input())
while (t):
	t-=1
	n =int(input())
	sum =(getSum(n));
	sum *=2022;
	sum %=(int)(10e9 +7);
	# cout <<sum << "\n";
	print(int(sum))