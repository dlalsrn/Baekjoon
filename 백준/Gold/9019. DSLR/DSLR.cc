#include <bits/stdc++.h>
using namespace std;

int T, A, B;
vector <bool> check;
queue <pair<int, string>> q;

int D(int n) {
	return n * 2 % 10000;
}

int S(int n) {
	return (n == 0 ? 9999 : n - 1);
}

int L(int n) {
	int s = 1;
	while (s * 10 <= n) {
		s *= 10;
	}
	int t = n / s;
	if (s == 1000) {
		n = n % s * 10;
		n += t;
	}
	else {
		n *= 10;
	}

	return n;
}

int R(int n) {
	int x = n % 10;
	n /= 10;
	n += x * 1000;
	return n;
}

void bfs() {
	while (!q.empty()) {
		int n = q.front().first;
		string cmd = q.front().second;
		q.pop();
		if (n == B) {
			cout << cmd << '\n';
			break;
		}

		int t = S(n);
		if (!check[t]) {
			check[t] = true;
			q.push({ t, cmd + 'S' });
		}
		if (n == 0) continue;
		t = D(n);
		if (!check[t]) {
			check[t] = true;
			q.push({ t, cmd + 'D' });
		}
		t = L(n);
		if (!check[t]) {
			check[t] = true;
			q.push({ t, cmd + 'L' });
		}
		t = R(n);
		if (!check[t]) {
			check[t] = true;
			q.push({ t, cmd + 'R' });
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	cin >> T;

	while (T--) {
		cin >> A >> B;
	
		check = vector<bool>(10001, false);
		q = queue<pair<int, string>>();

		q.push({ A, "" });
		check[A] = true;

		bfs();
	}
	return 0;
}