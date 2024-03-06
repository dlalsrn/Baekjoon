#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	int N;
	int ans = 1001;
	for (cin >> N; N--;) {
		int a, b;
		cin >> a >> b;
		if (a <= b)	ans = min(ans, b);
	}
	cout << (ans == 1001 ? -1 : ans);
	

}