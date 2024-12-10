#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll X1, X2, Y1, Y2, R1, R2;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

	double t = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
	cout << (t >= R1 + R2 ? "NO" : "YES");

	return 0;
}