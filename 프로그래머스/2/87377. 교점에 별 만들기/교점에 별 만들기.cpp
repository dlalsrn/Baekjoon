// 교점에 별 만들기
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    vector<pl> points;

    const ll INF = 1e63;
    ll minX = INF;
    ll maxX = -INF;
    ll minY = INF;
    ll maxY = -INF;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            ll AD_BC = (ll)line[i][0] * line[j][1] - (ll)line[i][1] * line[j][0];
            ll BF_ED = (ll)line[i][1] * line[j][2] - (ll)line[i][2] * line[j][1];
            ll EC_AF = (ll)line[i][2] * line[j][0] - (ll)line[i][0] * line[j][2];

            if (AD_BC == 0 || BF_ED % AD_BC != 0 || EC_AF % AD_BC != 0)
            {
                continue;
            }

            ll x = BF_ED / AD_BC;
            ll y = EC_AF / AD_BC;
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);

            points.push_back(make_pair(y, x));
        }
    }

    vector<vector<char>> map(maxY - minY + 1ll, vector<char>(maxX - minX + 1ll, '.'));

    for (int i = 0; i < points.size(); i++)
    {
        ll y = points[i].first - minY;
        ll x = points[i].second - minX;
        map[y][x] = '*';
    }

    for (int i = map.size() - 1; i >= 0; i--)
    {
        string s = "";

        for (int j = 0; j < map[i].size(); j++)
        {
            s += map[i][j];
        }
        answer.push_back(s);
    }

    return answer;
}