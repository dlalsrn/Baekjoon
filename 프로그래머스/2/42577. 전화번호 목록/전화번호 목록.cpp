#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> um;

    for (int i = 0; i < phone_book.size(); ++i)
    {
        string str = "";
        
        for (int j = 0; j < phone_book[i].size(); ++j)
        {
            str.push_back(phone_book[i][j]);
            ++um[str];;
            //str += phone_book[i][j];
        }
    }

    for (int i = 0; i < phone_book.size(); ++i)
    {
        if (um[phone_book[i]] > 1)
        {
            return false;
        }
    }

    return true;
}