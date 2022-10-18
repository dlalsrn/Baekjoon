#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Find(vector<int>* v, int min, int max, int x)
{
	int mid = (min + max) / 2;
	if ( (*v)[mid] == x)
		return mid;
	else if ((*v)[mid] < x)
		return Find(v, mid + 1, max, x);
	else
		return Find(v, min, mid - 1, x);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector <int> v;
	vector <int> t;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		t.push_back(num);
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for (int i = 0; i < N; i++)
	{
		cout << Find(&t, 0, t.size(), v[i]) << ' ';
	}
	return 0;
}