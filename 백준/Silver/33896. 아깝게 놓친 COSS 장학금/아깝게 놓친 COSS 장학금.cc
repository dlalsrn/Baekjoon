#include <bits/stdc++.h>
using namespace std;
using tt = tuple<int, int, string>;
int n;

string name;
int score;
int risk;
int cost;

vector<pair<int, string>> v;
vector<tuple<int, int, string>> t;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    for (int index = 0; index < n; index++)
    {
        cin >> name >> score >> risk >> cost;
        
        int total = (int)floor(pow(score, 3) / (float)(cost * (risk + 1)));

        v.push_back(make_pair(total, name));
        t.push_back(make_tuple(total, cost, name));
    }

    sort(v.begin(), v.end(), greater<>());

    auto compare = [](tt& a, tt& b) {
        if (get<0>(a) != get<0>(b)) 
            return get<0>(a) > get<0>(b); // 첫 번째 값은 내림차순
        if (get<1>(a) != get<1>(b)) 
            return get<1>(a) < get<1>(b); // 두 번째 값은 오름차순
        return get<2>(a) < get<2>(b);    // 세 번째 값은 오름차순
    };
    sort(t.begin(), t.end(), compare);

    cout << get<2>(t[1]);

    return 0;
}