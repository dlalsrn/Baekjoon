#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solution(string s) 
{
    string answer = "";
    sort(s.begin(), s.end(), greater<>());
    answer = s;
    return answer;
}