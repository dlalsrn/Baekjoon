#include <iostream>
using namespace std;

int S, N, M, ch, cnt = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> S >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		cin >> ch;
		if (ch)
		{
			if (cnt == S)
				S *= 2;
			cnt++;
		}
		else
			cnt--;
	}

	cout << S;

	return 0;
}