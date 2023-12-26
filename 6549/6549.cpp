#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int tmp;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        stack<pair<long long, long long> > st;
        long long ans = 0;
        long long j;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            j = 0;
            while (!st.empty())
            {
                if (st.top().first >= tmp)
                {
                    if (ans < st.top().first * ( st.top().second + j + 1))
                        ans =  st.top().first * ( st.top().second + j + 1);
                    j += st.top().second + 1;
                    st.pop();
                }
                else
                {
                    break;
                }     
            }
            st.push(make_pair(tmp, j));


        }
        j = 0;
        while (!st.empty())
        {
            if (ans < st.top().first * ( st.top().second + j + 1))
            { 
                ans =  st.top().first * ( st.top().second + j + 1);
            }
            j += st.top().second + 1;
            st.pop();
        }
        cout << ans << "\n";
    }
}