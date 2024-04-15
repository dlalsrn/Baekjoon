// 트리 순회
// 23.05.08
#include <bits/stdc++.h>
using namespace std;

vector <pair<char, char>> node;
int N;
char a, b, c;

void pre(char n)
{
	cout << n;
	if (node[n].first != -1) pre(node[n].first);
	if (node[n].second != -1) pre(node[n].second);
}

void in(char n)
{
	if (node[n].first != -1) in(node[n].first);
	cout << n;
	if (node[n].second != -1) in(node[n].second);
}

void post(char n)
{
	if (node[n].first != -1) post(node[n].first);
	if (node[n].second != -1) post(node[n].second);
	cout << n;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node.resize(100, { -1, -1 });

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (b != '.') node[a].first = b;
		if (c != '.') node[a].second = c;
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');

	return 0;
}