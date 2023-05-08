#include <iostream>
#include <vector>
using namespace std;

vector <int> node[26];
int N;
char a, b, c;

void pre(int n)
{
	cout << (char)(n + 'A');
	if (node[n][0] != -1)
		pre(node[n][0]);
	if (node[n][1] != -1)
		pre(node[n][1]);
}

void in(int n)
{
	if (node[n][0] != -1)
		in(node[n][0]);
	cout << (char)(n + 'A');
	if (node[n][1] != -1)
		in(node[n][1]);
}

void post(int n)
{
	if (node[n][0] != -1)
		post(node[n][0]);
	if (node[n][1] != -1)
		post(node[n][1]);
	cout << (char)(n + 'A');
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (b != '.')
			node[a - 'A'].push_back(b - 'A');
		else
			node[a - 'A'].push_back(-1);
		if (c != '.')
			node[a - 'A'].push_back(c - 'A');
		else
			node[a - 'A'].push_back(-1);
	}

	pre(0);
	cout << '\n';
	in(0);
	cout << '\n';
	post(0);

	return 0;
}