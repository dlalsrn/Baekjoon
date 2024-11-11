#include <bits/stdc++.h>
using namespace std;

int N, u, v;
vector<vector<int>> node;
vector <bool> ans;

bool DFS(int n, int pn) {
	bool t = false; // false면 잡으면 짐, true면 잡을 때 이김

	for (int x : node[n])
		if (x != pn) 
			t |= DFS(x, n);

	ans[n] = t;

	return (ans[n] ? false : true);
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node = vector<vector<int>>(N + 1);
	ans = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, -1);

	for (int i = 1; i <= N; i++) 
		cout << (ans[i] ? "donggggas\n" : "uppercut\n");

	return 0;
}