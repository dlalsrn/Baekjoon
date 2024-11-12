#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	if (N == 1) {
		cout << "-1 1";
	}
	else if (N == 2) {
		cout << "1 -1 -1 1";
	}
	else if (N == 3) {
		cout << "-1 -1 -1 1 1 1";
	}
	else {
		cout << "-1 1 -1 -1 ";
		for (int i = 0; i < N - 4; i++) cout << "1 -1 ";
		cout << "-1 1 1 1";
	}

	return 0;
}