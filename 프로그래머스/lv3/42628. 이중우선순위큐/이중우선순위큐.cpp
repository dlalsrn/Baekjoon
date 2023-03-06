#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
        vector<int> answer;
    multiset <int> s;
	for (int k = 0; k < operations.size(); k++)
	{
		if (operations[k][0] == 'I')
		{
			s.insert(stoi(operations[k].substr(2)));
		}
		else
		{
			if (!s.empty())
			{
				if (stoi(operations[k].substr(2)) == 1)
				{
					auto it = s.end();
					s.erase(--it);
				}
				else
					s.erase(s.begin());
			}
		}
	}

	if (s.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
	else
	{
		auto it = s.end();
        answer.push_back(*--it);
        answer.push_back(*s.begin());
	}

    return answer;
}