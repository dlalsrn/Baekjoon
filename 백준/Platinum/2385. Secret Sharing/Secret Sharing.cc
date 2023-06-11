#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, start;
string x, zero = "";
vector <string> v;

bool cmp1(string a, string b)
{
	return a + b < b + a;
}

bool cmp2(string a, string b)
{
	return a + zero + b < b + zero + a;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), cmp1);
	
	for (start = 0; start < N && v[start][0] == '0'; start++)
		zero += v[start];

	if (start == N)
		cout << "INVALID";
	else
	{
		//sort(v.begin() + start, v.end(), cmp2);
		int m = min_element(v.begin() + start, v.end(), cmp2) - v.begin();
		cout << v[m];
		for (int i = 0; i < N; i++)
			if (i != m)
				cout << v[i];
	}
	return 0;
}