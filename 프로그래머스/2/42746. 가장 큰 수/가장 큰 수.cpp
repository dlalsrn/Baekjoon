#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> v;

    for (int& x : numbers) v.push_back(to_string(x));

    auto cmp = [](string a, string b) {
        return a + b > b + a;
        };

    sort(v.begin(), v.end(), cmp);

    for (string& x : v) answer += x;

    return answer[0] == '0' ? "0" : answer;
}