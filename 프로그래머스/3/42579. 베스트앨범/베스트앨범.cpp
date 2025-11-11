// 베스트앨범
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using pis = pair<int, string>;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<string, vector<pii>> playList;
    map<string, int> play;
    vector<pis> count;

    for (int i = 0; i < genres.size(); i++)
    {
        play[genres[i]] += plays[i];
        playList[genres[i]].emplace_back(plays[i], i);
    }

    for (auto it = play.begin(); it != play.end(); it++)
    {
        auto [genre, cnt] = *it;
        count.emplace_back(cnt, genre);
    }

    sort(count.begin(), count.end());

    auto cmp = [](pii& a, pii& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };

    for (auto it = playList.begin(); it != playList.end(); it++)
    {
        vector<pii>& t = (*it).second;
        sort(t.begin(), t.end(), cmp);
    }

    while (!count.empty())
    {
        string genre = count.back().second;
        int cnt = count.back().first;
        count.pop_back();

        int sz = playList[genre].size();
        for (int i = 0; i < min(2, sz); i++)
        {
            answer.push_back(playList[genre][i].second);
        }
    }

    return answer;
}