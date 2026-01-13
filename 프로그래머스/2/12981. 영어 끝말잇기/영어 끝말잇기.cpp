#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    unordered_set<string> us;

    string prevWord = "";
    for (int i = 0; i < words.size() / n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            string curWord = words[i * n + j];
            if (prevWord != "" && (us.count(curWord) || (curWord[0] != prevWord.back())))
            {
                return { j + 1, i + 1 };
            }

            prevWord = curWord;
            us.insert(curWord);
        }
    }

    return { 0, 0 };
}