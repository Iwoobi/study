#include <iostream>
using namespace std;
#include <stack>
int main()
{
    cin.tie(0);
    stack<int> st;
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            st.pop();
        }
        else
            st.push(tmp);
    }
    int total = 0;
    while (!st.empty())
    {
        total += st.top();
        st.pop();
    }
    cout << total;
}