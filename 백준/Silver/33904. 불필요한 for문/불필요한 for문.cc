#include <bits/stdc++.h>
using namespace std;

string line;
vector<int> used(127, 0);
vector<pair<string, int>> lines;
map<string, int> m;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    int cnt = 1;
    while (true)
    {
        getline(cin, line);
        line.erase(0, line.find_first_not_of(' '));

        cin.ignore();

        if (line.find("for") == string::npos)
        {
            for (int index = 0; index < line.length(); index++)
            {
                used[line[index]]++;
            }
            
            lines.push_back(make_pair(line, cnt));

            break;
        }

        lines.push_back(make_pair(line, cnt));
        m[line] = cnt;
        cnt++;
    }

    cnt = 1;
    for (int index = 0; index < lines.size(); index++)
    {
        line = lines[index].first;
        // 연산식에서 사용된 적이 있고, 가장 안쪽의 for문이라면 or 연산식이라면
        if ((used[line[9]] && (lines[index].second == m[line])) || (index == lines.size() - 1))
        {
            for (int space = 0; space < cnt - 1; space++)
            {
                cout << ' ';
            }

            cout << line << '\n';
            cnt++;
        }
    }

    return 0;
}