#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

const long long MD = 1000000007;

long long d[110][3000];
char s[110];

int main()
{
	int i, j, k, T;


	d[0][0] = 1;
	for(i = 1; i <= 100; i++)
		for(j = 0; j <= i*25; j++)
			for(k = 0; k < 26 && k <= j; k++)
				d[i][j] = (d[i][j] + d[i-1][j-k]) % MD;

	for(scanf("%d",&T); T; T--)
	{
		getchar();
		scanf("%s", s);
		int n = strlen(s);

		for(j = 0, i = 0; i < n; i++) j += s[i] - 'a';
		printf("%Ld\n", (d[n][j] + MD - 1)% MD);
	}
	return 0;
}

