#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int kor;
	int eng;
	int math;
	string name;
}Node;

int N, kor, eng, math;
string name;
vector <Node> v;

bool compare(Node a, Node b)
{
	if (a.kor != b.kor) return a.kor > b.kor;
	if (a.eng != b.eng) return a.eng < b.eng;
	if (a.math != b.math) return a.math > b.math;
	return a.name < b.name;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> kor >> eng >> math;
		v.push_back({kor, eng, math, name});
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) cout << v[i].name << '\n';

	return 0;
}