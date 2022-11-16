#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> value;
vector <int> op;
vector <bool> visit_op;
int N, c, mx = -1000000000, mn = 1000000000;

void back(int ans, int cnt)
{
	if (cnt == N)
	{
		mx = max(mx, ans);
		mn = min(mn, ans);
		return;
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (visit_op[i])
			continue;
		visit_op[i] = true;
		if (op[i] == 0)
			back(ans + value[cnt], cnt + 1);
		else if (op[i] == 1)
			back(ans - value[cnt], cnt + 1);
		else if (op[i] == 2)
			back(ans * value[cnt], cnt + 1);
		else
			back(ans / value[cnt], cnt + 1);
		visit_op[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	value = vector<int>(N);
	visit_op = vector<bool>(N - 1, false);

	for (int i = 0; i < N; i++)
		cin >> value[i];

	for (int i = 0; i < 4; i++)
	{
		cin >> c;
		for (int j = 0; j < c; j++)
			op.push_back(i);
	}

	back(value[0], 1);

	cout << mx << '\n' << mn;
	return 0;
}