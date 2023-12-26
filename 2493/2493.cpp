#include <iostream>
#include <stack>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin >> num;
    int tmp;
    int index = 1;
    stack<pair<int, int> > st;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        while (!st.empty())
        {
            if (st.top().second > tmp)
            {
                cout << st.top().first << " ";
                break;
            }
            else
                st.pop();
        }
        if (st.empty())
            cout << "0" << " ";
        st.push(make_pair(index, tmp));
        index++;
    }
}