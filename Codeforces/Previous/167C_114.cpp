/*
 * Good game theory problem.
 */
#include <iostream>
#include <algorithm>
using namespace std;

bool f (long long x, long long y) {
	if (x < y) swap (x, y);
	if (!x || !y) return false;
	if (!f (y, x % y) ) return true;
	x = x / y;
	if ( y % 2 == 1 && x % 2 == 0) return true;
	if ( y % 2 == 0 && (x%(y+1))%2==0 ) return true;
	return false;
}

int main () {
	int T;
	long long x, y;
	for (cin >> T; T; T--) {
		cin >> x >> y;
		cout << (f (x, y) ? "First" : "Second") << endl;
	}
	return 0;
}



