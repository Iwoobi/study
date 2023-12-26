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
    int  count =0;
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
                if (st.top() == tmp[j])
                    st.pop();
                else
                    st.push(tmp[j]);
            }
        }
        if (st.empty())
            count++;
    }
    cout << count;
    
}