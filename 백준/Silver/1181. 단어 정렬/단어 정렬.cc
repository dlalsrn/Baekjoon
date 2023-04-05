#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();

}
int main() {


    int i, N;
    cin >> N;
    string temp;
    vector<string> ss;
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        ss.push_back(temp);
    }

    sort(ss.begin(), ss.end(), compare);

    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    for (i = 0; i < ss.size(); i++)
    {
        cout << ss[i] << "\n";
    }
    return 0;
}
