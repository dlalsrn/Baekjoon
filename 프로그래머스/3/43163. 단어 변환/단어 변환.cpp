// 단어 변환
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;
using psi = pair<string, int>;

int solution(string begin, string target, vector<string> words)
{
    queue<psi> q;
    unordered_map<string, bool> visit;
    unordered_map<string, bool> word;

    for (int i = 0; i < words.size(); i++)
    {
        word[words[i]] = true;
    }

    q.push(make_pair(begin, 0));
    visit[begin] = true;

    while (!q.empty())
    {
        auto [str, cnt] = q.front();
        q.pop();

        if (str == target)
        {
            return cnt;
        }

        for (int i = 0; i < str.size(); i++)
        {
            string temp = str;
            for (int j = 0; j < 26; j++)
            {
                temp[i] = 'a' + j;
                if (temp == str || !word[temp] || visit[temp]) continue;

                visit[temp] = true;
                q.push(make_pair(temp, cnt + 1));
            }
        }
    }

    return 0;
}