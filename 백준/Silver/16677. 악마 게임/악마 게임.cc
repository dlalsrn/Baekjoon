#include <iostream>
#include <vector>
using namespace std;

string s, ans = "";
int N;
float mx = 0.0;

bool IsValid(string origin, string cmp)
{
	int ori_Index = 0;
	int cmp_Index = 0;

	while (ori_Index < origin.size() && cmp_Index < cmp.size())
	{
		if (origin[ori_Index] == cmp[cmp_Index])
		{
			++ori_Index;
		}

		++cmp_Index;
	}

	return ori_Index == origin.size() ? true : false;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> s >> N;

	for (int i = 0; i < N; ++i)
	{
		string t;
		int v;

		cin >> t >> v;

		if (IsValid(s, t))
		{
			int count = t.size() - s.size();
			float w = (float)v / count;

			if (w > mx)
			{
				ans = t;
				mx = w;
			}
		}
	}

	cout << (ans == "" ? "No Jam" : ans) << '\n';

	return 0;
}