#include <iostream>
#include <limits.h>
using namespace std;
// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/archery-1/
long long gcd(long long a, int b) {
	if(b == 0) 
		return a;
	else 
		return gcd(b, a%b);
}
int main() {
	int t, k[15];
	cin >> t;
	while(t--) {
		int n;
		long long ans;
		cin >> n >> k[0];
		ans = k[0];
		for(int i=1; i<n; ++i) {
			cin >> k[i];
			ans = ans * k[i] / gcd(ans, k[i]);
		}
		cout << ans << endl;
	}
	return 0;
}