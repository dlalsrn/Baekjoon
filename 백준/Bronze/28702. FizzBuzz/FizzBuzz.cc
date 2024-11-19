#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b >> c;

	if (a[0] != 'F' && a[0] != 'B') {
		ans = stoi(a) + 3;
	}
	else if (b[0] != 'F' && b[0] != 'B') {
		ans = stoi(b) + 2;
	}
	else if (c[0] != 'F' && c[0] != 'B') {
		ans = stoi(c) + 1;
	}

	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (ans % 3 == 0) {
		cout << "Fizz";
	}
	else if (ans % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << ans;
	}

	return 0;
}