#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, string>;

int N;
string x;
vector <pi> v;
vector <string> ans;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.emplace_back(x.size(), x);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		x = v[i].second;
		bool check = true;

		for (int j = 0; j < ans.size(); j++) {
			if (ans[j].substr(0, x.size()) == x) {
				check = false;
				break;
			}
		}

		if (check) {
			ans.push_back(x);
		}
	}

	cout << ans.size();

	return 0;
}