#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> value;
vector <int> op(4);
int N, mx = -1000000000, mn = 1000000000;

void back(int ans, int cnt)
{
	if (cnt == N)
	{
		mx = max(mx, ans);
		mn = min(mn, ans);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!op[i])
			continue;
		op[i]--;
		if (i == 0)
			back(ans + value[cnt], cnt + 1);
		else if (i == 1)
			back(ans - value[cnt], cnt + 1);
		else if (i == 2)
			back(ans * value[cnt], cnt + 1);
		else
			back(ans / value[cnt], cnt + 1);
		op[i]++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	value = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> value[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	back(value[0], 1);

	cout << mx << '\n' << mn;
	return 0;
}