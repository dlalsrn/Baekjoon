#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    stack <int> st;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (a == "pop")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (a == "size")
            cout << st.size() << '\n';
        else if (a == "top")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
        else
            cout << st.empty() << '\n';
    }
    return 0;
}