#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int A, B;
	cin >> A >> B;
	string a;
	vector <string> v1;
	vector <string> v2;

	for (int i = 0; i < A; i++)
	{
		cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < B; i++)
	{
		cin >> a;
		v1.push_back(a);
	}

	sort(v1.begin(), v1.end());
	for (int i = 0; i < A + B; i++)
	{
		if (v1[i] == v1[i + 1])
		{
			v2.push_back(v1[i]);
			i++;
		}
	}
	cout << v2.size() << '\n';
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << '\n';
    return 0;
}