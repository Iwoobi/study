#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    stack<pair<unsigned int, int>> st;
    int j;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        while (!st.empty())
        {
            if (st.top().first < j)
            {
                ans += st.top().second + 1 ;
                if (st.size() == st.top().second)
                    ans--;
                st.pop();
            }
            else
                break;
        }
        if (!st.empty() && st.top().first == j)
        {
            st.push(make_pair(j , st.top().second + 1));
        }
        else
            st.push(make_pair(j,1));
    }
    while (!st.empty())
    {
        ans += st.top().second;
        if (st.size() ==  st.top().second)
            ans--;
        st.pop();
    }
    cout << ans;
}