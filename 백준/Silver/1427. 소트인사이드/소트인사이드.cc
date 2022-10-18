#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	vector <int> v;
	string a;
	cin >> a;

	for (int i = 0; i < a.size(); i++)
		v.push_back(a[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < a.size(); i++)
		printf("%d", v[a.size()-i-1]-48);
	return 0;
}