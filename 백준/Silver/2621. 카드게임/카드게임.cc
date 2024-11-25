#include <bits/stdc++.h>
using namespace std;

int n1, n2, n3,n4, n5, a;
char c1, c2, c3, c4, c5, b;
vector <pair<int, char>> v;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> b >> a;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	n1 = v[0].first; c1 = v[0].second;
	n2 = v[1].first; c2 = v[1].second;
	n3 = v[2].first; c3 = v[2].second;
	n4 = v[3].first; c4 = v[3].second;
	n5 = v[4].first; c5 = v[4].second;

	if (c1 == c2 && c2 == c3 && c3 == c4 && c4 == c5 && n1 + 1 == n2 && n2 + 1 == n3 && n3 + 1 == n4 && n4 + 1 == n5) {
		cout << n5 + 900;
	}
	else if (n1 == n2 && n2 == n3 && n3 == n4) { // 2
		cout << n1 + 800;
	}
	else if (n2 == n3 && n3 == n4 && n4 == n5) {
		cout << n2 + 800;
	}
	else if (n1 == n2 && n3 == n4 && n4 == n5) { // 3
		cout << n3 * 10 + n1 + 700;
	}
	else if (n1 == n2 && n2 == n3 && n4 == n5) {
		cout << n1 * 10 + n4 + 700;
	}
	else if (c1 == c2 && c2 && c3 && c3 == c4 && c4 == c5) { // 4
		cout << n5 + 600;
	}
	else if (n1 + 1 == n2 && n2 + 1 == n3 && n3 + 1 == n4 && n4 + 1 == n5) { // 5
		cout << n5 + 500;
	}
	else if (n1 == n2 && n2 == n3) { // 6
		cout << n1 + 400;
	}
	else if (n2 == n3 && n3 == n4) {
		cout << n2 + 400;
	}
	else if (n3 == n4 && n4 == n5) {
		cout << n3 + 400;
	}
	else if (n1 == n2 && n3 == n4) { // 7
		cout << n3 * 10 + n1 + 300;
	}
	else if (n1 == n2 && n4 == n5) {
		cout << n4 * 10 + n1 + 300;
	}
	else if (n2 == n3 && n4 == n5) {
		cout << n4 * 10 + n2 + 300;
	}
	else if (n1 == n2) { // 8
		cout << n1 + 200;
	}
	else if (n2 == n3) {
		cout << n2 + 200;
	}
	else if (n3 == n4) {
		cout << n3 + 200;
	}
	else if (n4 == n5) {
		cout << n4 + 200;
	}
	else {
		cout << n5 + 100;
	}

	return 0;
}