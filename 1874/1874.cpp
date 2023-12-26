#include <iostream>
using namespace std;
#include <stack>
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    stack<int> st;
    int num;
    cin >> num;
    char *result = new char[2 * num];
    int j = 0;
    int i = 1;
    int k = 0;
    while (k < 2 * num)
    {
        cin >> j;
        while (i <= j)
        {
            result[k] = '+';
            k++;
            st.push(i);
            i++;
        }
        if (st.top() != j)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            result[k] = '-';
            st.pop();
            k++;
        }
    }
    for (int i = 0; i < 2*num; i++)
        cout << result[i] << "\n";
}