#include <iostream>
#include <vector>
using namespace std;

int c, h, H, M, S, second, cnt = 0;
char t;
vector <bool> v(86400, true);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> h;

	for (int i = 0; i < c; i++)
	{
		cin >> H >> t >> M >> t >> S;
		second = H * 3600 + M * 60 + S;
		for (int j = second; j < second + 40; j++)
			v[j] = false;
	}

	for (int i = 0; i < h; i++)
	{
		cin >> H >> t >> M >> t >> S;
		second = H * 3600 + M * 60 + S;
		for (int j = second; j < second + 40; j++)
			v[j] = false;
	}

	for (int i = 0; i < 86400; i++)
		if (v[i])
			cnt++;

	cout << cnt;

	return 0;
}