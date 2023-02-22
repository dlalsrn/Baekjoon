// 전투의 신
// 22.12.22
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, temp;
ll A, Ap, B, Bp;
ll att, mx = 0;
ll X, Y;

int main(void)
{
	cin >> N >> A >> Ap >> B >> Bp;
	for (ll i = 0; Ap * i <= N; i++)
	{
		temp = N;
		temp -= Ap * i;
		att = A * i + (temp / Bp) * B;

		if (mx < att)
		{
			X = i;
			Y = (temp / Bp);
			mx = att;
		}
	}

	cout << X << ' ' << Y;

	return 0;

}