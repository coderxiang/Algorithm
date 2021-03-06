#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int N = 80011;

vector<int> tr[N];
unsigned long long ans;
int cap[N];
int n;

void DFS (int u, int pre) {
	int i, j, k;
	cap[u] = 1;
	unsigned long long tmp = 0; 
	for (i = 0; i < tr[u].size(); ++i) {
		if ((j = tr[u][i]) != pre) {
			DFS (j, u);
			tmp += (unsigned long long) cap[j] * cap[u];
			cap[u] += cap[j];
		}
	}
	ans -= tmp * (tmp + 2 * (unsigned long long) cap[u] * (n - cap[u]));
}

int main () {
	int i, j, k;
	cin >> n;
	ans = (unsigned long long) n * (n - 1) / 2;
	ans *= ans;
	for (k = n - 1; k; --k) {
		cin >> i >> j;
		tr[i].push_back (j);
		tr[j].push_back (i);
	}
	DFS (1, 0);
	cout << ans << endl;
	return 0;
}
	
