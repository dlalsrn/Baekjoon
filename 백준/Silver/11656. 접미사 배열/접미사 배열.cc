#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	string a;
	int n;
	vector <string> v;
	cin >> a;
	n = a.size();

	for (int i = 0; i < n; i++)
		v.push_back(a.substr(i));

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
    return 0;
}