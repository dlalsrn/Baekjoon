#include <bits/stdc++.h>
using namespace std;

int T, a, b, c;
set <int> s;
vector <int> A, B, C;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> a;
		A.resize(a);
		for (int i = 0; i < a; i++) cin >> A[i];
		
		cin >> b;
		B.resize(b);
		for (int i = 0; i < b; i++) cin >> B[i];

		cin >> c;
		C.resize(c);
		for (int i = 0; i < c; i++) cin >> C[i];

		s.clear();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				for (int k = 0; k < c; k++)
				{
					int x = A[i] + B[j] + C[k];
					int t = x;
					while (t)
					{
						if (t % 10 != 5 && t % 10 != 8) break;
						t /= 10;
					}
					if (!t) s.insert(x);
				}
			}
		}

		cout << s.size() << '\n';
	}

	return 0;
}