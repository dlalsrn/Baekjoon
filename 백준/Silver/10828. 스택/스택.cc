#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    stack <int> st;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a[0] == 'p')
        {
            if (a[1] == 'u')
            {
                int k;
                cin >> k;
                st.push(k);
            }
            else if (a[1] == 'o')
            {
                if (st.empty())
                    cout << -1 << "\n";
                else
                {
                    cout << st.top() << "\n";
                    st.pop();
                }
            }
        }
        else if (a[0] == 's')
            cout << st.size() << "\n";
        else if (a[0] == 'e')
            cout << st.empty() << "\n";
        else if (a[0] == 't')
            if (st.empty())
                cout << -1 << "\n";
            else
                cout << st.top() << "\n";
    }
    return 0;
}