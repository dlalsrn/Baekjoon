// 황금 칵테일
// 22.12.22
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

map <string, double> m;
vector <string> v;
int N;
double a;
string x;
bool TF = false;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> a;
		if (!m[x])
			v.push_back(x);
		m[x] += a;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (floor(m[v[i]] * 1.618) == floor(m[v[j]]) || floor(m[v[i]]) == floor(m[v[j]] * 1.618))
			{
				TF = true;
				break;
			}
		}
		if (TF)
			break;
	}

	cout << (TF ? "Delicious!" : "Not Delicious...");
	return 0;
}