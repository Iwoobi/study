#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin >> num;
    int j;
    stack<pair<int, int> > st;
    int *ans = new int[num];
    fill_n(ans,num, -1);
    int index,n;
    for (int i = 0; i < num; i++)
    {
        cin >> j;
        while (!st.empty())
        {
            if (st.top().second < j)
            {
                ans[st.top().first] = j;
                st.pop();
            }
            else
            {
                break;
            }
        }
        st.push(make_pair(i, j));
    }
    for (int i = 0; i< num; i++)
        cout << ans[i] << " ";
}