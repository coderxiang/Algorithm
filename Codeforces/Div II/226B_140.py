r = lambda : map (int, raw_input ().split ());
n = input ();
a = sorted (r (), reverse = True);

sm = [0] * n;
for i in xrange (1, n):
	sm[i] = a[i] + sm[i - 1];

ans = [0] * 100010;

for q in xrange (1 , 100001):
	cnt = 0; x = 0;
	while True:
		x += 1;
		ans[q] += (sm[min (cnt + q**x, n - 1)] - sm[cnt]) * x;
		cnt += q ** x;
		if cnt >= n - 1:
			break

q = input ();
q = r ();
for x in q:
	print (ans[x]),

	
	
		
		
	
	
	

