#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int A, B, n, cnt = 0;
	cin >> A >> B;
	vector <int> v;

	for (int i = 0; i < A; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	for (int i = 0; i < B; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == v[i + 1])
		{
			cnt++;
			i++;
		}
	}
	cout << v.size() - (cnt*2) << '\n';
    return 0;
}