#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ary;
vector <int> Left;
vector <int> Right;
int N, mx = 0;

int main(void)
{
	cin >> N;

	ary = vector<int>(N);
	Left = vector<int>(N, 1);
	Right = vector<int>(N, 1);
	
	for (int i = 0; i < N; i++)
		cin >> ary[i];

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (ary[i] < ary[j])
				Left[j] = max(Left[i] + 1, Left[j]);

	for (int i = N - 1; i > 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (ary[j] > ary[i])
				Right[j] = max(Right[i] + 1, Right[j]);

	for (int i = 0; i < N; i++)
		mx = max(mx, Left[i] + Right[i] - 1);
	cout << mx;
	return 0;
}