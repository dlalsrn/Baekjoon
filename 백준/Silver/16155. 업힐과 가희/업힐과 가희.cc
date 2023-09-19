#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b);

int main() {

    ll n;

    ll x1, x2;


    cin >> n;

    vector<vector<ll>> uphill(n + 1, vector<ll>(2, 0));

    for (ll i = 0; i < n + 1; i++) {
        cin >> uphill[i][0] >> uphill[i][1];
    }

    cin >> x1 >> x2;
    ll tmp_x, tmp_y;
    tmp_x = uphill[0][0];
    tmp_y = uphill[0][1];
    ll a = 0;
    ll b = 0;
    ll c = 0;
    ll d = 0;
    ll ss = 0;
    ll rr = 0;
    ll ay, ax, a_x, t_y, ra, rb, r_x, r_y = 0;
    for (ll i = 0; i < n + 1; i++) {

        if (x1 == uphill[i][0]) {
            a = uphill[i][1];

            ax = 1;

            ss = a;

            tmp_x = uphill[i][0];
            tmp_y = uphill[i][1];

            // cout << "ss : " << ss << '\n';
            // cout << "ax : " << ax << '\n';

            c++;
        }
        if (x2 == uphill[i][0]) {
            b = uphill[i][1];
            rb = 1;
            rr = b;
            d++;
        }

        if (c != 1 && x1 <= uphill[i][0]) {

            ax = uphill[i][0] - tmp_x;
            ay = uphill[i][1] - tmp_y;
            a_x = x1 - tmp_x;
            t_y = tmp_y * ax;
            ss = ay * a_x + t_y;



            // a = ss / ax
            // cout << "ss : " << ss << '\n';
            // cout << "ax : " << ax << '\n';
            c++;
            a = ((tmp_y - uphill[i][1]) / (tmp_x - uphill[i][0])) * (x1 - tmp_x) + tmp_y;
        }

        if (d != 1 && x2 <= uphill[i][0]) {
            // cout << "tmp_x : " << tmp_x << '\n';
            // cout << "tmp_y : " << tmp_y << '\n';
            // cout << uphill[i][0] << '\n';

            ra = uphill[i][1] - tmp_y;
            rb = uphill[i][0] - tmp_x;
            r_x = x2 - tmp_x;
            r_y = tmp_y * rb;
            rr = ra * r_x + r_y;

            // b = rr / rb
            // cout << "rr : " << rr << '\n';
            // cout << "rb : " << rb << '\n';
            d++;
            b = ((tmp_y - uphill[i][1]) / (tmp_x - uphill[i][0])) * (x2 - tmp_x) + tmp_y;
            break;
        }
        tmp_x = uphill[i][0];
        tmp_y = uphill[i][1];

    }
    // cout << "a : " << a << '\n';
    // cout << "b : " << b << '\n';

    // cout << "x1 : " << x1 << '\n';
    // cout << "x2 : " << x2 << '\n';
    // a = ss / ax
    // b = rr / rb
    // cout << "ss : " << ss << '\n';
    // cout << "ax : " << ax << '\n';
    // cout << "rr : " << rr << '\n';
    // cout << "rb : " << rb << '\n';

    ll child = (ss * rb - rr * ax);
    ll parent = (ax * rb);

    //ll sum_y = abs(a - b);
    // cout << "child : " << child << '\n';
    // cout << "parent : " << parent << '\n';

    ll sum_x = (x2 - x1);

    sum_x = (sum_x * parent);
    ll sum_y = (child);

    // cout << "sum_y : " << sum_y << '\n';
    // cout << "sum_X :  " << sum_x << '\n';
    a = abs(sum_y);
    b = abs(sum_x);
    if (a < b)
        swap(a, b);
    ll g = gcd(a, b);

    if ((sum_y % sum_x) != 0) {
        cout << abs(sum_y / g) << '/' << abs(sum_x / g) << '\n';
    }
    else {
        cout << abs(sum_y / sum_x) << '\n';
    }
}

ll gcd(ll a, ll b)
{
    ll tmp = 0;
    while (1) {
        if (b == 0) {
            break;
        }
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
