#include <iostream>
#include <vector>
using namespace std;
int N, L, R, num;
vector <int> v;
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	L += v[0];
	R += v[1];

	for (int i = 2; i < N; i++)
	{
		if (L == R)
		{
			L += v[i];
		}
		else if (L < R)
		{
			L += v[i];
		}
		else
		{
			R += v[i];
		}
	}

	int diff = abs(L - R);
	int cnt = 0;
	while (diff != 0)
	{
		if (diff >= 100)
			diff -= 100;
		else if (diff >= 50)
			diff -= 50;
		else if (diff >= 20)
			diff -= 20;
		else if (diff >= 10)
			diff -= 10;
		else if (diff >= 5)
			diff -= 5;
		else if (diff >= 2)
			diff -= 2;
		else
			diff -= 1;
		cnt++;
	}
	cout << cnt;
}