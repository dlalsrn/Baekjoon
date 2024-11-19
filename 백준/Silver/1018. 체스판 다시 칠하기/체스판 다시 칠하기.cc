#include <bits/stdc++.h>
using namespace std;

int N, M, B, W, ans;
char first;
bool TF;
string x;
vector <string> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	ans = N * M;

	for (int a = 0; a <= N - 8; a++) {
		for (int b = 0; b <= M - 8; b++) {
			TF = true;
			B = W = 0;

			for (int i = a; i < a + 8; i++) {
				bool check = TF;
				for (int j = b; j < b + 8; j++) {
					if (check) {
						if (v[i][j] == 'W') B++;
					}
					else {
						if (v[i][j] == 'B') W++;
					}
					check = !check;
				}
				TF = !TF;
			}
			ans = min(ans, B + W);
			
			TF = false;
			B = W = 0;
			for (int i = a; i < a + 8; i++) {
				bool check = TF;
				for (int j = b; j < b + 8; j++) {
					if (check) {
						if (v[i][j] == 'W') B++;
					}
					else {
						if (v[i][j] == 'B') W++;
					}
					check = !check;
				}
				TF = !TF;
			}
			ans = min(ans, B + W);
		}
	}

	cout << ans;

	return 0;
}