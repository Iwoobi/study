#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    int j = 0;
    while(1)
    {
        cin >> a;
        if (a.length() == 1 && a[0] == '0')
            break;
        for (int i = 0; i <= a.length() / 2; i++)
        {
            if (a[i] != a[a.length() - 1 - i])
            {
                cout << "no\n";
                j = 2;
                break;
            }
            j = 1;
        }
        if (j == 1)
            cout << "yes\n";
    }
}