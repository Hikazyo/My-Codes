#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m, n, t;

    cin >> m;
    for (long long i = 0; i < m; i++)
    {
        vector<long long> map;
        cin >> n;
        for (long long k = 0; k < n; k++)
        {
            cin >> t;
            map.push_back(t);
        }

        long long count = 0;
        unordered_map<long long, vector<long long>> hx;

        for (long long j = 0; j < n - 4; j++)
        {

            hx[map[j] + map[j + 2] - map[j + 4]].push_back(j);
        }

        for (const auto &p : hx)
        {
            const vector<long long> &v = p.second;
            long long temp = v.size();
            count += temp * (temp - 1) / 2;

            unordered_set<long long> st(v.begin(), v.end());
            for (long long x : v)
            {
                if (st.count(x + 2))
                    count--;
                if (st.count(x + 4))
                    count--;
            }
        }
        cout << count << endl;
    }

    return 0;
}