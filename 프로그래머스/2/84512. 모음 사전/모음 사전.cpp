#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v = {"A", "E", "I", "O", "U"};
vector<string> words;

void DFS(string str, int cnt)
{
    if (str.size() == cnt)
    {
        words.push_back(str);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        DFS(str + v[i], cnt);
    }
}

int solution(string word)
{
    int answer = 0;

    DFS("", 1);
    DFS("", 2);
    DFS("", 3);
    DFS("", 4);
    DFS("", 5);

    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());

    answer = lower_bound(words.begin(), words.end(), word) - words.begin() + 1;

    return answer;
}