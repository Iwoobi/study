#include <iostream>
#include <stack>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin >> num;
    stack<int> st;
    int j;
    unsigned int res = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> j;
        if (!st.empty())
        {
            while (st.top() <= j)
            {
                st.pop();
                res += st.size();
                if (st.empty())
                    break; 
            }
        }
        st.push(j);
    }
    while (!st.empty())
    {
        st.pop();
        res += st.size();
    }
    cout << res;
}