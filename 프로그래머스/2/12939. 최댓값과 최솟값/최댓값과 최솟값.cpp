#include <bits/stdc++.h>
using namespace std;

string solution(string s)
{
    string answer = "";
    istringstream iss(s);
    vector<int> v;

    int t;
    while (iss >> t)
    {
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    answer = to_string(v[0]) + ' ' + to_string(v[v.size() - 1]);

    return answer;
}