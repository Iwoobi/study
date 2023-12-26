#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++)
        {
            if (st.empty())
                st.push(tmp[j]);
            else
            {
                if (tmp[j] == '(')
                    st.push('(');
                else
                {
                    if (st.top() == '(')
                        st.pop();
                }
            }
        }
        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
}