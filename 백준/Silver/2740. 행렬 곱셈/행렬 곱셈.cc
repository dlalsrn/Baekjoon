#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector <vector<int>> A, B, ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;
	A = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	B = vector<vector<int>>(M, vector<int>(K));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	ans = vector<vector<int>>(N, vector<int>(K, 0));

	for (int i = 0; i < N; i++)
		for (int k = 0; k < K; k++)
			for (int j = 0; j < M; j++)
				ans[i][k] += A[i][j] * B[j][k];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}